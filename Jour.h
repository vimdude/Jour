/* -+----1----+----2----+----3----+----4----+----5----+----6----+----7----+- */
/* Abdel Ouahed Said                                       le 4 octobre 2001 */
/* ------------------------------------------------------------------------- */
/*                                Jour.h                                     */
/* ------------------------------------------------------------------------- */
/*                                                                           */
/* Fichier d'entete                                                          */
/*                                                                           */
/* ------------------------------------------------------------------------- */

#ifndef JOUR
#define JOUR


#include <iostream.h>

/**
* Un Jour est defini comme un jour de la semaine
*/
// -----------------------------------------------------------------
class Jour
// -----------------------------------------------------------------
{
	private: int numero;
	public:  static const char * const jours[];

	/**
	* Construit le jour Dimanche
	*/
	// -------------------------------------------------------------
	public: Jour();
	// -------------------------------------------------------------
	
	/**
	* Construit un jour avec une valeur specifiee.
	*/
	// -------------------------------------------------------------
	public: Jour(int);
	// -------------------------------------------------------------
	
	/**
	* Construit un jour avec un jour en chaine de caractairevaleur
	* specifiee.
	*/
	// -------------------------------------------------------------
	public: Jour(char *);
	// -------------------------------------------------------------
	
	/**
	* Operateur de conversion de type Jour en un type entier.
	*/
	// -------------------------------------------------------------
	public: operator int( void ) const;
	// -------------------------------------------------------------
	
	// -------------------------------------------------------------
	public: operator ++ ( void );
	// -------------------------------------------------------------
	
	// -------------------------------------------------------------
	public: operator ++ ( int );
	// -------------------------------------------------------------
	
	// -------------------------------------------------------------
	public: operator -- ( void );
	// -------------------------------------------------------------
	
	// -------------------------------------------------------------
	public: operator -- ( int );
	// -------------------------------------------------------------
	
	/**
	* affiche le continu d'un objet de type jour
	*/
	// -------------------------------------------------------------
	public: friend ostream & operator <<(ostream & sortie,
		const Jour & jour);
	// -------------------------------------------------------------
};

#endif
































