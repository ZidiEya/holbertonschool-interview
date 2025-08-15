Parcourir la chaîne s caractère par caractère.

Vérifier à chaque position si on peut trouver une concaténation de tous les mots (words), dans n’importe quel ordre, sans caractère entre eux.

Retourner un tableau dynamique contenant toutes les positions où c’est vrai.

Mettre dans *n le nombre de résultats trouvés.

Étapes de la logique
Longueurs

Tous les mots ont la même longueur → word_len = strlen(words[0])

Longueur totale d’une combinaison = word_len * nb_words

À chaque index i dans s

Prendre un tableau temporaire used[] pour savoir quels mots ont déjà été utilisés.

Extraire des segments de longueur word_len et vérifier s’ils correspondent à un mot qui n’a pas encore été pris.

Si on réussit à prendre nb_words mots consécutifs, i est un index valide.

Stockage

On utilise malloc pour stocker les indices trouvés, on agrandit avec realloc si besoin.

