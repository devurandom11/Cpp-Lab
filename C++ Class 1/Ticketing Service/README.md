# Ticketing Service

Given `main()`, complete the program to add people to a queue. The program should read in a list of people's names including `"You"` (ending with -1), adding each person to the `peopleInQueue` queue. Then, remove each person from the queue until `"You"` is at the head of the queue. Include print statements as shown in the example below.

Ex. If the input is:

```cpp
Zadie Smith
Tom Sawyer
You
Louisa Alcott
-1
```

the output is:

```cpp
Welcome to the ticketing service...
You are number 3 in the queue.
Zadie Smith has purchased a ticket.
You are now number 2
Tom Sawyer has purchased a ticket.
You are now number 1
You can now purchase your ticket!
```
