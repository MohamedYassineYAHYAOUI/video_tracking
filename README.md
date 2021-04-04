# tracking video avec OpenGl

Ce projet consiste à traquer une zone de l'image ayant une couleur particulière à partir d'une vidéo ou d'une webcam.
En pratique, l'utilisateur lancera la vidéo et sélectionnera à la souris une zone de l'image (ou bien par défaut le milieu de l'image). Cette zone correspondra à un objet, d'une couleur particulière non connue à l'avance, qu'il faudra tracker, c'est à dire suivre d'une image à l'autre pendant la vidéo.

La méthode de tracking pourra faire intervenir :

de changements d'espace colorimétrique
de la recherche de couleur silimaire
du tracking standard openCV (optical flow)
de la prévision de trajectoire
tout ce à quoi vous pourrez penser