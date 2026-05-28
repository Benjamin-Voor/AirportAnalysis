# Graph-Based Airport Connectivity and Flight Route Optimization System in C++
### Instructor: Dr. Paniz Abedin
### Semester: Spring 2024
### Course Name: Data Structures & Algorithms
### Course ID: COP3415
### By: Brian Tran, Robert Baumgarten, and Benjamin Voor
Using C++ in Replit, we took a csv dataset containing 384 entries of airport codes, locations, distances, and cost values, and converted it into a graph data structure by creating a vector representing each airport and an adjacency matrix where each edge is a flight. We used Dijkstra's algorithm to calculate the shortest path between 2 airports

# Presentation
Our project's project description was assigned in `Assignment.pdf`, and we presented our project to the class using the PowerPoint file called `Graph-Based Airport Connectivity and Flight Route Optimization System.pptx`
<img width="1500" height="843" alt="Screenshot 2025-07-16 161107" src="https://github.com/user-attachments/assets/c2a8c196-01df-4fa8-87da-739d457c7354" />

## Skills
* Group academic project with live collaboration 
* C++
* Data Structures
* Object-Oriented Programming
* Replit app, with live collaboration (which was moved to a GitHub repository)

## Instructions
We uploaded everything to https://www.onlinegdb.com/online_c++_compiler or replit.com to run it. 

# Project Description
For the rest of this README, I'm just gonna copy-paste from the assignments' .pdf so you know what we did:

## Learning Outcomes
• Graph Theory and Data Structures: We learned about graph data structures, how to represent
them in code, and how they can model real-world problems. We understood concepts like nodes
(vertices) and edges, and how to store them using adjacency lists or matrices.

• Algorithm Implementation: Implementing graph algorithms like Dijkstra's algorithm, DFS, BFS,
Prim’s, and Kruskal’s has deepened our understanding of these algorithms, their time complexities, and
their applications in finding the shortest or most efficient paths.

• Data Processing and Manipulation: Working with datasets, such as airport and flight information,
has given us experience in data processing, filtering, and transformation, which are valuable skills
in data analysis and software development.

## Project Description
This project aims to develop a comprehensive system for modeling and optimizing airport connectivity
and flight routes. The core of the system is a graph-based representation, where each node represents an
airport, and edges represent direct flights between airports. This model allows for the application of
various graph algorithms to analyze and optimize the network of flights.

## Dataset
The dataset, named "airports.csv," consists of four columns: Origin_airport, Destination_airport,
Origin_city, Destination_city, Distance and Cost. This dataset is required for implementing all the tasks
mentioned above. The Origin_airport and Destination_airport columns use the abbreviated format for
airport names, such as PIT, ATL, ORD, etc. The Origin_city and Destination_city columns provide the
actual names of the cities and states. The dataset contains 384 entries and includes flight information for
140 different airports.

