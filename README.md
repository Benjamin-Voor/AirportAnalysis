# Graph-Based-Airport-Connectivity-and-Flight-Route-Optimization-System-written-in-cpp
Using C++ in Replit, we converted a .csv into a graph, where each vertex represented an airport and each edge represented a flight. We used Dijkstra’s algorithm in order to calculate the shortest path between two airports. We also separated two-letter state codes from a string in the .csv in order to group vertices together by state.

# Presentation
We presented this in class at the end of the Spring 2024 semester. You can find the PowerPoint we used in the folder named "Submission" in the file named "Graph-Based Airport Connectivity and Flight Route Optimization System.pptx" (Everything that we submitted to the professor is in the "submission" folder).
<img width="1500" height="843" alt="Screenshot 2025-07-16 161107" src="https://github.com/user-attachments/assets/c2a8c196-01df-4fa8-87da-739d457c7354" />

# Accreditations
The .pdf files were not written by ourselves. Some .pdf's may lay out the assignment, and other .pdf's may include basic concepts to help us when we were stuck, which imo is a far better way to learn than plugging everything into ChatGPT.

# Notes
This was moved over from Replit manually because Replit kept throwing me errors and wouldn't use my linked GitHub account to do it automatically. 

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

