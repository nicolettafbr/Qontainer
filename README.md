<img src="/view/images/qontainer.png" width="auto" height="auto" align="center">

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
                
!!IMPORTANT!!: As the app opens you will be asked to select a file. Choose the file named *db.txt* that you will find in the root folder of the *Qontainer* directory you have just cloned: this is the actual database where all the actual exercises reside and where you will be able to save them. So, as soon as you compile the project and click on the executable, go on and select the *db.txt* file present in the *Qontainer* folder. Now have fun! :)


## GUI

My aim was to develop a GUI that's both quite simple to use AND catchy at the same time. You let me know if I did a good job or not.
Here’s what the GUI looks like:

### Home Page

Home page (which redirects you to the *Add* page):                                                                                        
<img src="/GUI_img/home_page.png" width="500" height="500" align="center">

### Add an exercise

Now onto the add itself. Here is what the *Add* page looks like for different exercises:

Strength:                                                                                                                                 
<img src="/GUI_img/aggiungi_forza.png" width="500" height="500">

Hypertrophy:                                                                                                                              
<img src="/GUI_img/aggiungi_ip.png" width="500" height="500">

HIIT:                                                                                                                                     
<img src="/GUI_img/aggiungi_hiit.png" width="500" height="500">

LISS:                                                                                                                                     
<img src="/GUI_img/aggiungi_liss.png" width="500" height="500">

When you add and exercise successfully you are greeted by a very big man with a VERY big bicep. Hope that motivates you to work out even harder the next time!                                                                                                                    
<img src="/GUI_img/aggiunta_riuscita.png" width="500" height="500">

### View your exercises

If you click on *Visualizza* and then on one of the random buttons on the left this is what you'll see:                                   
<img src="/GUI_img/visualizza.png" width="500" height="500">                                                                              
One thing I really wanted to implement was that for every kind of exercise the app calculates for you useful things such as:
1. STRENGHT TRAINING: One Rep Max, %Weight Lifted, Volume
2. HYPERTROPHY: Volume
3. HIIT: Total duration of your workout, you maximum Hear Rate, the cardio zone you were in
4. LISS: Total duration of your workout, you maximum Hear Rate, the cardio zone you were in

### Search for an exercise

If you aim is to search for a particular exercise you can insert both the name and the date of execution and you will get back the exercises that match those two elements:                                                                                                   
<img src="/GUI_img/cerca.png" width="500" height="500">

I haven't implemented a thorough research algorithm yet (my bad), so if you leave one of those two search fields blank you will get an error message that looks like the following:
<img src="/GUI_img/ricerca_fallita.png" width="500" height="500">

### Manage your exercises

Should you decide to modify/delete any of the exercises, just click on *Gestisci*:                                                        
<img src="/GUI_img/gestisci.png" width="500" height="500">
<img src="/GUI_img/modifica.png" width="500" height="500">

Whenever you decide to delete an exercise, you will be asked to confirm your decision:                                                    
<img src="/GUI_img/elimina.png" width="500" height="500">


## Other (more technical) things
As far as all the technical stuff goes, Qontainer is a container which main purpose is to contain a series of miscellaneous elements (no pun intended).
To pursue this purpose we were asked to develop a hierarchy using C++ and I chose to base mine on fitness exercises (the complete hierarchy and other technicalities can be found in the file ‘relazione.pdf’). Realised within the Qt framework, the GUI is also completely written in C++.

