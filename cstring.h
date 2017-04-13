/* 
 * File:   cstring.h
 * Author: Adrian
 *
 * Created on 11. avril 2017, 12:49
 */

#ifndef CSTRING_H
#define	CSTRING_H

class String{
    private:
        unsigned int _capacity; //taille réservée
        unsigned int _size; //taille effective
        char * _str; //chaîne de caractère courrante
        /**
         * Construction de l'instance String courrante
         * @param str
         */
        void constructString(const char * str);
    public:
        /**
         * Construction chaîne vide ""
         */
        String();

        /**
         * Construction à partir d'une chaîne de caractère
         * constante. Exemple: "bonjour"
         * @param str
         */
        String(const char * const str);

        /**
         * Construction à partir d'un autre String
         * @param str
         */
        String(const String& str);

        /**
         * Construction à partir d'un caractère 'x'
         * @param chr
         */
        String(const char& chr);

        /**
         * Construction à partir d'un entier
         * @param entier
         */
        String(const int& entier);

        /**
         * Construction à partir d'un double
         * @param reel
         */
        String(const double& reel);

        /**
         * Construction à partir d'un booléen
         * @param booleen
         */
        String(const bool& booleen);

        /**
         * Destructeur - delete de _str
         */
        ~String();

        /**
         * Opérateur de cast en const char*, retourne _str
         * utile pour l'affichage par l'utilisation d'opérateur
         * de flux de sortie
         * @return
         */
        operator const char*() const;

        /**
         * Fonction concaténation deux instances String
         * @param b
         * @return nouveau String résultat
         */
        friend String operator+(String a, const String &b);

        /**
         * Fonction concaténation instance String et chaîne
         * constante
         * @param b
         * @return nouveau String résultat
         */
        friend String operator+(String a, const char *b);

        /**
         * Fonction concaténation instance String et caractère
         * String("fo") + 'o' = String("foo")
         * @param b
         * @return nouveau String résultat
         */
        friend String operator+(String a, const char &b);

        /**
         * Fonction concaténation instance String et caractère
         * 'f' + String("oo") = String("foo")
         * @param b
         * @return nouveau String résultat
         */
        friend String operator+(const char &b, String a);

        /**
         * Concaténation + affectation à l'instance appelante
         * entre deux instance String
         * @param b
         * @return instance modifiée
         */
        String& operator+=(const String &b);

        /**
         * Concaténation + affectation à l'instance appelante
         * entre instance String et chaîne constante
         * @param b
         * @return instance modifiée
         */
        String& operator+=(const char* const b);

        /**
         * Concaténation + affectation à l'instance appelante
         * entre instance String et caractère
         * @param b
         * @return instance modifiée
         */
        String& operator+=(const char &b);

        /**
         * Concaténation + affectation à l'instance appelante
         * entre instance String et chaîne constante
         * @param other
         */
        void append(const char* other);

        /**
         * Concaténation + affectation à l'instance appelante
         * entre instance String et caractère
         * @param b
         */
        void append(const char& b);

        /**
         * Concaténation + affectation à l'instance appelante
         * entre deux instance String
         * @param b
         */
        void append(const String& b);

        /**
         * Surchage == comparaison de deux instances String
         * @param str
         * @return vrai si chaîne équivalentes
         */
        bool operator == (const String &str) const;

        /**
         * Surchage == comparaison d'une instance String et
         * d'une chaîne constante
         * @param str
         * @return vrai si chaîne équivalente /!\ retourne faux
         * si fait dans le sens inverse "chaine" != String(chaine)
         */
        bool operator == (const char* const str) const;

        /**
         * Surchage == comparaison de deux instances String
         * @param str
         * @return vrai si chaîne équivalentes
         */
        bool equals(const String &str) const;

        /**
         * Surchage == comparaison d'une instance String et
         * d'une chaîne constante
         * @param str
         * @return vrai si chaîne équivalente
         */
        bool equals(const char* const str) const;

        /**
         * Retourne la taille de la chaîne
         * @return
         */
        unsigned int size() const;

        /**
         * Accède au caractère situé à l'index "index"
         * @param index
         * @return référence sur l'index
         */
        char& operator[](unsigned int index) const;

        /**
         * Accède au caractère situé à l'index "index"
         * @param index
         * @return référence sur l'index
         */
        char& at(unsigned int index) const;

        /**
         * Surcharge opérateur d'affectation
         * @param str
         * @return
         */
        String& operator=(const char* const str);
        String& operator=(const String& str);


        /**
         * Retourne la sous-chaîne de from à to
         * @param from index premier caractère
         * @param to index de fin (précédent dernier caractère)
         * @return
         */
        char& operator[](int index) const;
        char& at(int index) const;

        String substr(unsigned int from, unsigned int to) const;
};

#endif	/* CSTRING_H */