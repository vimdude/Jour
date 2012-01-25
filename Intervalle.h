/* -+----1----+----2----+----3----+----4----+----5----+----6----+----7----+- */
/* Abdel Said                                                le 20 aout 2001 */
/* ========================================================================= */
/*                               Intervalle.h                                */
/* ========================================================================= */
/*                                                                           */
/* Fichier d'interface de la classe Intervalle.                              */
/*                                                                           */
/* ========================================================================= */

#ifndef INTERVALLE
#define INTERVALLE

#include <iostream.h>
#include <exception>

/**
* Un Intervalle est defini comme l'espace compris entre deux limites,
* le minimum et le maximum
*/
// ============================================================================
template< typename Nombre >
class Intervalle
// ============================================================================
{
	public: static const char * const nom;
	private: Nombre minimum;
	private: Nombre maximum;
	private: bool minimumInclus;
	private: bool maximumInclus;

	/**
	* Declenchee lorsque le minimum est superieur au maximum..
	*/
	// ==========================================================================
	public: class LimitesIncompatibles
	// ==========================================================================
	{
		public: static const char * const message;
		/**
		* Insere l'exception dans un stream.
		*/
		// ------------------------------------------------------------------------
		//friend ostream & operator << ( ostream & sortie,
		//	const LimitesIncompatibles & erreur );
		// ------------------------------------------------------------------------
	};

	/**
	* Construit un Intervalle unitaire [0, 1]
	*/
	// --------------------------------------------------------------------------
	public: Intervalle( );
	// --------------------------------------------------------------------------

	/**
	* Construit un IntervalleEntier avec les deux limites specifiees.
	* Si le nouveau minimum est superieur au maximum courant, declenche
	* l'exception LimitesIncompatibles.
	*/
	// --------------------------------------------------------------------------
	public: Intervalle( Nombre minimum, Nombre maximum )
		throw( LimitesIncompatibles );
	// --------------------------------------------------------------------------

	/**
	* Destructeur.
	*/
	// --------------------------------------------------------------------------
	public: ~Intervalle( );
	// --------------------------------------------------------------------------

	/**
	* Modifie le minimum de l'intervalle. Si le nouveau minimum est superieur
	* au maximum courant, declenche l'exception LimitesIncompatibles.
	*/
	// --------------------------------------------------------------------------
	public: void modifierMinimum( Nombre nouveauMinimum )
		throw( LimitesIncompatibles );
	// --------------------------------------------------------------------------

	/**
	* Modifie le maximum de l'intervalle. Si le nouveau maximum est inferieur
	* au minimum courant, genere l'exception LimitesIncompatibles.
	*/
	// --------------------------------------------------------------------------
	public: void modifierMaximum( Nombre nouveauMaximum )
		throw( LimitesIncompatibles );
	// --------------------------------------------------------------------------

	/**
	* renvoie le minimum de l'intervalle.
	*/
	// --------------------------------------------------------------------------
	public: Nombre fournirMinimum( void );
	// --------------------------------------------------------------------------

	/**
	* renvoie le maximum de l'intervalle.
	*/
	// --------------------------------------------------------------------------
	public: Nombre fournirMaximum( void );
	// --------------------------------------------------------------------------

	/**
	* Specifie si le minimum est oui ou non inclus dans l'intervalle
	*/
	// --------------------------------------------------------------------------
	public: void modifierMinimumInclus( bool inclus );
	// --------------------------------------------------------------------------

	/**
	* Specifie si le maximum est oui ou non inclus dans l'intervalle
	*/
	// --------------------------------------------------------------------------
	public: void modifierMaximumInclus( bool inclus );
	// --------------------------------------------------------------------------

	/**
	* envoie true si le minimum est inclus dans l'intervalle, non autrement.
	*/
	// --------------------------------------------------------------------------
	public: bool estMinimumInclus( void );
	// --------------------------------------------------------------------------

	/**
	* Specifie si le maximum est oui ou non inclus dans l'intervalle
	*/
	// --------------------------------------------------------------------------
	public: bool estMaximumInclus( void );
	// --------------------------------------------------------------------------

	/**
	* Renvoie vrai si nombre est inclus dans l'intervalle, faux autrement.
	*/
	// --------------------------------------------------------------------------
	public: bool inclus( Nombre nombre );
	// --------------------------------------------------------------------------

	/**
	* Affiche l'intervalle sous le format ]|[<minimum>..<maximum>]|[.
	*/
	// --------------------------------------------------------------------------
	friend ostream & operator << ( ostream & sortie,
		const Intervalle< Nombre > & intervalle );
	// --------------------------------------------------------------------------
};

// ----------------------------------------------------------------------------
template< typename Nombre >
ostream & operator << ( ostream & sortie,
	const Intervalle< Nombre >::LimitesIncompatibles & erreur );
// ----------------------------------------------------------------------------

#endif /* INTERVALLE */
