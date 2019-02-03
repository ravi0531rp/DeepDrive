# DeepDrive
The Repository contains all the files and descriptive Jupyter notebooks for my implementation of a Deep Neural Network based Car Prototype.
The ultimate and prime objective of this Project is to create a pool of DeepCars which will learn together and drive autonomously without human intervention.
The Project consists of several phases of operation, given its scale:-
  1) Phase I - (Completed)
     This phase involves building a simple bot based on heuristics that can navigate in any environment without collision. It was based on      Arduino and Ultrasonic Sensors. The basic Obstacle detection and avoiding algorithm makes it possible.
     
  2) Phase II -(Completed)
     This phase is quite identical to phase I except for the fact that all the same is implemented on Raspberry Pi. The interfacing with        Raspberry Pi gave quite a few advantages with the computation power.
     
  3) Phase III -(Completed)
     This phase involved 5 ultrasonic Sensors interfaced with Raspberry Pi. But, the twist was that i used a Multi Layer Perceptron Model        to train the car from the data learnt by manually driving the car using a bluetooth module and simultaneous logging the data to an SD      card. This was a tedious task but it was quite interseting.
     We used Tensorflow as a framework to train the network on Google Colaboratory as we get free K80 GPU. 
     
  4) Phase IV -(Ongoing)
     This is the current ongoing phase where alongwith the five sensors and a Pi Camera to get realtime visual feed. 
