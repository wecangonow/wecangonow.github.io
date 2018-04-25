---
layout: post
title: gracefully shutdown of goroutines
category: go
---

## 原文地址

<http://vrecan.github.io/post/graceful_goroutnes/>

### Overview

A common problem people new to Go tend to run into is managing goroutines. Starting a goroutine is easy but how do you guarantee it closed gracefully when you are ready to exit? 

First, lets create a struct that will manage our goroutine. In this case it's just going to be one but there are no restrictions here.

``` go
//App is an example struct that will run goroutines

type App struct {
    wg *sync.WaitGroup // allow us to wait for close
    done chan bool
    Data chan string
}

func NewApp()(app *App) {
    app = &App{
        wg: &sync.WaitGroup{},
        done: make(chan bool, 1),
        Data: make(chan string, 100),
    }
    return app
}
```

With this we can now add a new methods to start and run our goroutine. Fist, our start method which will increment our wait group and run our goroutine. It's important to increment the wait group before you spin up the goroutine
otherwise you can have a race condition on close.

```go
// Start goroutines
func (a *App) Start() {
    a.wg.Add(1)
    go a.runSelect()
}
```

There are two main ways to handle signaling for shutdown. This example shows both for completeness. The first thing we are going using a channel called done in a select statement which allow us to get a signal from something
external telling us it's time to shutdown.

The other way of managing shutdown of a goroutine is to just close it when you are done sending things to the channel. The benifit of this approach is that you will always proccess all of the messge before you exit. Obviously this
could be a negative as well if you don't want to process everything on the queue before a shutdown.

```go
//Run with select statment to manage shutdown
func (a *App) runSelect() {
    defer a.wg.Done()
loop:
    for {
        select {
        case <-a.done:
            fmt.Println("Detected close doing cleanup and exiting")
            a.runClose()
            break loop
            //do cleanup if needed
        case s, ok := <-a.Data:
            if ok { // ok will tell us if the channel has been shutdown
                fmt.Println("select: ", s)
            } else {
                //done processing all messages exit
                fmt.Println("Breaking loop")
                break loop
            }
        }
    }
}

// process all message on the queue until we get close message
func (a *App) runcClose() {
    for s := range a.Data {
        fmt.Println("close: ", s)
    }
}
```

Now it's time for our simple close method that will send  our done singal and also close our channel. In a real
application you want to make sure to only close a Go channel after you can guarantee all the senders are done. Go
channels will panic if you try to send to a closed channel.

```go
//Cleanly close background routines
func (a *App) Close() {
    if a != nil {
        a.done <- true
        close(a.Data) //this lets the recv know there is no more data
        a.wg.Wait()
    }
}
```

Example main loop for completeness.
```go
func main() {
    app := NewApp()
    app.Start()
    for i := 1; i <= 100; i++ {
        app.Data <- fmt.Sprintf("TESTING %d", i)
    }

    app.Close()
}
```

### Conclusion

I hope this example was helpful. Every new Go developer seems to get stuck on managing closing goroutines and this information has been helpful in explains the pitfalls of common patterns to shutdown.
