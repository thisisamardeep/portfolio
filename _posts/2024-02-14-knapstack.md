---
title: 0/1 Knapsack Problem
published: true
share-description: ""
tags: [ leetcode ]
share-img: /img/rust.png
readtime: true
permalink: "/0-1-Knapsack-problem"
share-description: "0/1 Knapsack problem and its variations"
comments: false
---

We are given N items where each item has some weight (wi) and value (vi) associated with it.
We are also given a bag with capacity W. The target is to put the items into the bag such that
the sum of values associated with them is the maximum possible.Note that here we can either put an item completely into
the bag or cannot put it at all.

First Approach:

Ideally this is a enhanced recursion or so called dynamic programming problem.
Consider the universe of all possible subsets of items.We need to find the subset having the maximum value.
There are 2 ways in which we can start reducing our universe,we can reduce our universe to exclude subsets
which cannot be part of the result or we can iterate over the result and find the subset having the
maximum value.We use a combination of both ways.

> Inputs:

> profit[ ] = { 160, 1000, 120 };

> int weight[ ] = { 10, 20, 30 };

The above 2 arrays have the profit and weight of each item.

> W =50 W is the weight of the knapstack.

> int n =3 n number of items

Basically we try to reduce our universe.
We start from the end of the vector profit.Whether we start from end or from start or from any order
is not important.What is important is that we pick each item only one.
Every item can either be in our result set or it cannot be.

Case 1) Item at position 3 is in our result set.In that can we can reduce our knapstack problem
to 2 items.So our final result is profit of last item plus knapstack result of n-1 items.

Case 2) Item at position 3 is not in our result set.
So we can reduce our knapstack problem to size 2.

Case 3) Size of last item is more that the maximum weight knapstack can hold.
We just return from this case since we know that this item cannot be part of final result.

Let us start with 2 simple c++ files the driver code and our recursive code:

```c++
// Driver Code
using namespace std;
int main()
{
int profit[] = {
60, 100, 120
};
int weight[] = { 10, 20, 30 };
int W = 50;
int n = 3;
cout << knapSack(W, weight, profit, n);
return 0;
} 
```

```c++
// Recursive  Function
using namespace std;
int knapSack(int W, int wt[], int val[], int n)
{
// to be done
return 0;
} 
```

Now in every call we reduce n (the last paramter.).Since we are using this to iterate over the vector
so techically we reduce our universe.If there is nothing left n is 0 or the size of last item in more than the
size of the knapstack we just return 0.But where does this 0 go it goes in the calculation of max up in the call
stack.Since our function has to return int even if n==0 or the size of last item in more than the
size of the knapstack we have to return 0.It is possible that 0 is the result .. i.e the edge case when all items
are of size greater than the knapstack.
So at this point we are here.
It is important to note that the paramter n is the nth item of the vector.
But nth item of the  vector has index n-1 ..So we use wt[n-1] > W
```cpp
// Recursive  Function
using namespace std;
int knapSack(int W, int wt[], int val[], int n)
{
if (n ==0){
return 0;
}
if (wt[n-1] > W){
return knapSack( W, wt, val, n-1);
}


// to be done
return 0;
} 
```

The program is terminated and the output reveals where the panic was triggered. As a bonus, the application can be
configured via an environment variable to show its backtrace (stack unwinding).

```plain
$ cargo run
Hello, world!
thread 'main' panicked at 'Panic in the main thread!', src/main.rs:2:5
note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace
```

It becomes even more intriguing when the exit code of the process is checked right after termination:

```plain
$ echo $?
101
```

Rust sets the exit code to `101` explicitly when a process panics by calling the `exit` function, while `abort` signals
the kernel to kill the process (a detailed explanation of how `abort` works on Unix systems can be found in an earlier
[post](/how-signals-are-handled-in-a-docker-container){:target="_blank"}). In practice, this means that no core dumps
are
generated in the default configuration.

Now, let us take a look at what happens when `panic!` is called from a sub-thread:

```rust
use std::thread;

fn main() {

    let handle = thread::spawn( || {
        println!("Thread started!");
        panic!("Panic in a thread!");
    });

    handle.join();

    println!("Hello, world!");
}
```

Output:

```plain
$ cargo run
Thread started!
thread '<unnamed>' panicked at 'Panic in a thread!', src/main.rs:7:9
note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace
Hello, world!

$ echo $?
0
```

The output clearly states that the thread has panicked but the main thread continues running, even after calling `join`!
It can thus be concluded that `panic` does not exit the entire process, but rather only the current thread; this is
completely different from C’s `abort`!

My continued interest in the Rust language grows precisely due to features such as this, where the language provides
elegant methods for terminating a process in the case where a background thread crashes.

If we were to force an ultimatum on the result of `join`, the shortest way is to `unwrap` the return value:

```rust
...
handle.join().unwrap();
...
```

The result contains an error and unwrapping leads to panic in the main thread:

```plain
$ cargo run
Thread started!
thread '<unnamed>' panicked at 'Panic in a thread!', src/main.rs:7:9
note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace
thread 'main' panicked at 'called `Result::unwrap()` on an `Err` value: Any', src/main.rs:10:19
```

Another way to manipulate the output of `join` is to check the result and decide what to do during runtime; the
following example uses `match`:

```rust
match handle.join() {
    Ok(_) => println!("Joined!"),
    Err(_) => println!("Join failed"),
};
```

Note that this example only prints the error and the program still exits with `0`.

But wait, there's more!
For those who are not big fans of change, Rust even provides the possibility to configure `panic!` to call `abort`; this
can be done via Cargo.toml in the project:

```toml
[profile.dev]
panic = "abort"

[profile.release]
panic = "abort"
```

The result is the same as calling `abort` in C: the application is terminated with `SIGABRT` and if the system is
configured, a core dump is generated:

```plain
$ cargo run
Thread started!
thread '<unnamed>' panicked at 'Panic in a thread!', src/main.rs:7:9
note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace
[1]    67943 abort      cargo run
134
```

Rust's flexibility truly does not cease to amaze and I will diligently continue to provide such examples which I believe
other enthusiasts should be aware of and use.


