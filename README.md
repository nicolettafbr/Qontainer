# Qontainer

## Brief Summary

Qontainer is the OOP Project I developed during my second year as a Computer Science student at the University of Padua.

Qontainer is a fitness app that lets you track your exercises to make your gym sessions easier than ever!

You can choose from four different types of exercises: strength (forza), hypertrophy (ipertrofia) and two types of cardio, namely liss (low intensity steady state cardio) and hiit (high intensity steady state cardio). 

For each kind of exercise you are asked to fill in some specific fields required to calculate super useful and rad things such as your one rep max or your cardio training zone, i.e. in every strength exercise you are asked for the number of sets, reps and the weight used, whereas for every hiit session you perform you should put in the number of intervals of work/rest performed and how much they lasted.

For the time being the app is only available in Italian, but an English translation is DEFINITELY on my to-do list!

## Compilation

HOW TO COMPILE: Given you have qmake installed, just type 

                qmake project.pro
                make
                
On your command line. Then click on the executable in the root folder the two aforementioned commands have created and you're good to go.
                
!!IMPORTANT!!: As the app opens you will be asked to select a file. Choose the file named 'db.txt' that you will find in the root folder of the Qontainer directory you have just cloned: this is the actual database where all the actual exercises reside and where you will be able to save them. So, as soon as you compile the project and click on the executable, go on and select the 'db.txt' file present in the Qontainer folder. Now have fun! :)

## GUI

Here’s what the GUI looks like:



As far as all the technical stuff goes, Qontainer is a container which main purpose is to contain a series of miscellaneous elements (no pun intended).
To pursue this purpose we were asked to develop a hierarchy using C++ and I chose to base mine on fitness exercises (the complete hierarchy and other technicalities can be found in the file ‘relazione.pdf’).

