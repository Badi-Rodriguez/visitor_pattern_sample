# Visitor Pattern Sample (C++)

### What is the Visitor Pattern?

The **Visitor pattern** is a **behavioral design pattern** that allows you to separate an algorithm from the objects on which it operates. It enables you to add new operations to a group of related classes **without modifying their source code**, making it especially useful when the object structure is stable but you need to perform many unrelated operations on it.

The pattern involves two main components:

- **Visitor**: An object that implements operations to be performed on elements of the object structure.
- **Element (or Visitable)**: An object that accepts a visitor and lets it access its data through a common interface.

The **key benefit** of the Visitor pattern is **extensibility**. In real-world systems, modifying existing classes—especially those already in production—can be risky. The Visitor pattern mitigates this by enabling you to add new behaviors externally via visitor objects, **without changing the original class definitions**.

This is particularly useful in scenarios involving **polymorphism**, where different types of elements share a common interface. The Visitor pattern leverages **double dispatch**—a technique that determines the correct operation to perform based on both the visitor and the element types—ensuring that the right code runs for each combination.

> For example, if you have a collection of different shapes (circles, rectangles, triangles), you can use the Visitor pattern to add new operations like exporting to XML or calculating area, without changing the shape classes themselves. (You do however "add more code", but it's not in a way that disrupts current working implementations!)

## Why Use the Visitor Pattern?
- **Separation of concerns:** Keeps data structures and operations separate.
- **Open/Closed Principle:** Add new operations without changing existing classes.
- **Extensibility:** Easily introduce new behaviors for a family of objects.

## How is the Visitor Pattern Implemented Here?
This project demonstrates the Visitor pattern using a simple geometry example in C++. The code is modularized for clarity and maintainability.

### Key Components
- **Shapes:**
  - `Circle`, `Rectangle`, `Triangle`, and `CompoundShape` (a composite of shapes).
  - All shapes inherit from a common abstract base class.
- **Visitors:**
  - `AreaVisitor`: Calculates the area of each shape.
  - `XMLExportVisitor`: Exports each shape's data as XML.
- **Double Dispatch:**
  - Each shape implements an `accept` method that takes a visitor. The visitor then calls the appropriate method for that shape type.
- **Modular Structure:**
  - Each class and visitor is defined in its own header/source file for clarity.

### Example Flow
1. **Create shapes:** Instantiate various shapes (e.g., `Circle`, `Rectangle`, etc.).
2. **Create visitors:** Instantiate visitors for different operations (e.g., area calculation, XML export).
3. **Accept visitors:** Each shape calls `accept(visitor)`, which triggers the visitor's operation for that shape.

### Directory Structure
- All modularized code is in the `improved version` directory.
- The main directory contains a placeholder `main.cpp` that points users to the improved version.

## Summary
This project is a clear, modern C++ example of the Visitor pattern, showing how to:
- Separate operations from data structures
- Add new operations easily
- Keep code organized and maintainable

For a complete analysis of the current code, feel free to go over to the `improved-version` directory! It contains all the classes and code used for the application.

That would be it from me, thank you for reading, and I hope this implementation was useful for you to understand the perhaps most legedary design pattern in history! You won't get fired for using it, trust! Heheh!!! >:3

Badi Rodriguez, future superstar game developer logging out!

## New Feature: Unified Output to .txt File

A new visitor, `FileOutputVisitor`, has been added to the project! This visitor captures the output of both the `AreaVisitor` (area calculations) and the `XMLExportVisitor` (XML export of shapes) and writes them into a single `.txt` file in the main directory.

### How It Works
- The `FileOutputVisitor` is used just like the other visitors: simply call `accept(fileVisitor)` on your shapes.
- All output that would normally be printed to the console by the area and XML visitors is instead captured and written to a file.
- The file is named after a parameter you provide (e.g., `shape_output.txt`).
- The output file contains two sections: area calculations and XML export, making it easy to review or share results.

### Why This Solves the Problem
Previously, if you wanted to save the results of both visitors, you would have to manually copy console output or modify each visitor. Now, with `FileOutputVisitor`, you can:
- Automatically generate a clean, organized `.txt` file with all relevant output.
- Avoid modifying existing visitor logic or shape classes.
- Easily change the output filename by passing a different parameter to the visitor.

**This approach leverages the extensibility of the Visitor pattern, showing how new behaviors can be added without disrupting existing code!**

---
