# CLI Task Manager

A command-line to-do list written in C++. Add, list, complete, and delete
tasks from a simple menu. Tasks are saved to `tasks.txt` and loaded back
on startup.

## Build

    g++ -o task_manager src/main.cpp

## Run

    ./task_manager

## Menu

1. Add task: enter a description
2. List tasks: shows each task with `[ ]` (open) or `[X]` (done)
3. Complete task: enter a task id
4. Delete task: enter a task id (remaining ids are renumbered)
5. Quit

## Data

Tasks are stored in `tasks.txt` in the working directory, one per line as
`id|completed|description`. The file is created on first save.