#!/usr/bin/python3
# coding: utf-8
# Début de programme python pour transformer une instance du sac à dos en LP
# 	le fichier peut contenir des lignes de commentaires commençant par #
# 	la première ligne non commentée doit contenir la capacité
# 	les autres lignes doivent décrire les objets, 1 par ligne, d'abord une id puis le poids puis la valeur

fichier_entree = open("set-cover-1.msc",'r')
fichier_sortie = open("set-cover-1.lp",'w')

objectif = ""
subject = ""
variables = ""
objectif_sep = ""
deja_capacite = False

for ligne in fichier_entree:
	toks = ligne.split()
	if len(toks) >0 and toks[0] != 'c':
		if not deja_capacite: capacite = toks[0] ; deja_capacite = True
		else: 
			objectif = objectif + objectif_sep + toks[2] + " x" + toks[0]
			subject = subject + objectif_sep + toks[1] + " x" + toks[0]
			variables =  variables + "x" + toks[0] + " "
			objectif_sep = " + "

subject = subject + " <= " + capacite

fichier_sortie.write("Maximize\n")
fichier_sortie.write("  " + objectif + "\n")
fichier_sortie.write("Subject To\n")
fichier_sortie.write("  weight: ")
fichier_sortie.write(subject +"\n")
fichier_sortie.write("Binary \n")
fichier_sortie.write("  " + variables + "\n")
fichier_sortie.write("End")

fichier_entree.close()
fichier_sortie.close()

