Title: C Budgeting Program
Author: Daniel Miller

I’ve been working on a chess program in c to help me study my openings for a couple months now.  I hadn’t worked with c in a while when I started about eight months ago, and about three months ago I hit a brick wall of segfaults. Somehow I created a race condition in my code, and the the errors kept popping up. Even when I fixed one error, a similar race condition error would show up in the next set of code that I tried to compile.

I came across an article about two months ago talking about teaching a c programming class using the original c-programming language book, published in the late 70s, by Kernighan and Ritchie. I bought the book, and I was ready to start a new project using code and examples from the book.  The examples in the book contain a unique style that focuses on brevity rather than simplicity. Many of the examples have while loops with assignments inside the conditional statement, rather than on a second line in the body of the loop. For loops have multiple initializations and incrementers and/or decrementers in a single line. Additionally, functions and variables of the same type are always declared on the same line.

My first project is an accounting program that uses the basic styling of the c-programming language book. I was hoping to get the program down to 100 lines or less, but I have gone through it a few times, and any further shortening will break the style in ways that don’t feel true to the style of the book. At 138 lines, it is more than a simple function, but at the same time, it is not so big and unruly that it will be too hard to understand later.

To use the program, first compile it:

`gcc home.c`

Then, write down all of your transactions for the month in the following format:

`date <tab> description <tab> amount <tab> account <tab> entity/group <newline>`. 

You can do this by creating a fancy web ui, or inputing the data in a spreadsheet program and then exporting it.

Here is an example input file:

```
20220809        net-paid        +1750.00        chasejnt        CHECKING
20220911        sbux-caf        -3.62000        subject        CHECKING
```
I’ve written the program in a very loosely tested manner, so the tabs need to be exactly one tab in between each string. Although not strictly necessary, the character length for each field is perferably eight characters. This allows the tabs to line up nicely when the data is printed out. Optionally, amounts have a + or - in front of them to keep the transaction amount clear as either a positive or negative value with respect to the account that the money is being transferred.

The benefit of the program comes from how the fields are added together. When the same account or entity/group is used more than once, the program will find all transactions that belong to the same account or group and add them up to provide an output. 

After compiling and creating an input file, the following bash command is how I run it:

`cat input | ./a.out`

From the above example, the output looks like this:

```
--------
accounts:
--------
chasejnt         1750.00
sbuxacct          -3.62

--------
entities:
--------
CHECKING         1746.38
```

