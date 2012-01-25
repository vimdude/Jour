/* -+----1----+----2----+----3----+----4----+----5----+----6----+----7----+- */
/* Abdel Said                                                le 20 aout 2001 */
/* ========================================================================= */
/*                               Intervalle.cpp                              */
/* ========================================================================= */
/*                                                                           */
/* Fichier de definition de la classe Intervalle.                            */
/*                                                                           */
/* ========================================================================= */

#include <iostream.h>
#include <exception>

#include "Intervalle.h"

template< typename Nombre >
const char * const Intervalle< Nombre >::nom = "EntierBorne";

/**
* Construit un Intervalle unitaire [0, 1]
*/
// ----------------------------------------------------------------------------
template< typename Nombre >
Intervalle< Nombre >::Intervalle( )
// ----------------------------------------------------------------------------
	: minimum( ( Nombre )0 ), maximum( ( Nombre )1 ),
		minimumInclus( true ), maximumInclus( true )
{
}

/**
* Construit un IntervalleEntier avec les deux limites specifiees.
* Si le nouveau minimum est superieur au maximum courant, declenche
* l'exception LimitesIncompatibles.
*/
// ----------------------------------------------------------------------------
template< typename Nombre >
Intervalle< Nombre >::Intervalle( Nombre minimum, Nombre maximum )
	throw( LimitesIncompatibles )
	: minimum( minimum ), maximum( maximum ),
		minimumInclus( true ), maximumInclus( true )
// ----------------------------------------------------------------------------
{
	if ( minimum > maximum ) throw LimitesIncompatibles( );
}

/**
* Destructeur.
*/
// ----------------------------------------------------------------------------
template< typename Nombre >
Intervalle< Nombre >::~Intervalle( )
// ----------------------------------------------------------------------------
{
}

/**
* Modifie le minimum de l'intervalle. Si le nouveau minimum est superieur
* au maximum courant, declenche l'exception LimitesIncompatibles.
*/
// ----------------------------------------------------------------------------
template< typename Nombre >
void Intervalle< Nombre >::modifierMinimum( Nombre nouveauMinimum )
	throw( Intervalle::LimitesIncompatibles )
// ----------------------------------------------------------------------------
{
	if ( nouveauMinimum > maximum )
		throw Intervalle::LimitesIncompatibles( );
	minimum = nouveauMinimum;
}

/**
* Modifie le maximum de l'intervalle. Si le nouveau maximum est inferieur
* au minimum courant, genere l'exception LimitesIncompatibles.
*/
// ----------------------------------------------------------------------------
template< typename Nombre >
void Intervalle< Nombre >::modifierMaximum( Nombre nouveauMaximum )
	throw( Intervalle::LimitesIncompatibles )
// ----------------------------------------------------------------------------
{
	if ( nouveauMaximum < minimum )
		throw Intervalle::LimitesIncompatibles( );
	maximum = nouveauMaximum;
}

/**
* renvoie le minimum de l'intervalle.
*/
// ----------------------------------------------------------------------------
template< typename Nombre >
Nombre Intervalle< Nombre >::fournirMinimum( void )
// ----------------------------------------------------------------------------
{
	return minimum;
}

/**
* renvoie le maximum de l'intervalle.
*/
// ----------------------------------------------------------------------------
template< typename Nombre >
Nombre Intervalle< Nombre >::fournirMaximum( void )
// ----------------------------------------------------------------------------
{
	return maximum;
}

/**
* Specifie si le minimum est oui ou non inclus dans l'intervalle
*/
// ----------------------------------------------------------------------------
template< typename Nombre >
void Intervalle< Nombre >::modifierMinimumInclus( bool inclus )
// ----------------------------------------------------------------------------
{
	minimumInclus = inclus;
}

/**
* Specifie si le maximum est oui ou non inclus dans l'intervalle
*/
// ----------------------------------------------------------------------------
template< typename Nombre >
void Intervalle< Nombre >::modifierMaximumInclus( bool inclus )
// ----------------------------------------------------------------------------
{
	maximumInclus = inclus;
}

/**
* envoie true si le minimum est inclus dans l'intervalle, non autrement.
*/
// ----------------------------------------------------------------------------
template< typename Nombre >
inline bool Intervalle< Nombre >::estMinimumInclus( void )
// ----------------------------------------------------------------------------
{	
	return minimumInclus;
}

/**
* envoie true si le maximum est inclus dans l'intervalle, non autrement.
*/
// ----------------------------------------------------------------------------
template< typename Nombre >
inline bool Intervalle< Nombre >::estMaximumInclus( void )
// ----------------------------------------------------------------------------
{	
	return maximumInclus;
}

/**
* Renvoie vrai si nombre est inclus dans l'intervalle, faux autrement.
*/
// ----------------------------------------------------------------------------
template< typename Nombre >
bool Intervalle< Nombre >::inclus( Nombre nombre )
// ----------------------------------------------------------------------------
{
	if ( nombre < minimum ) return false;
	if ( !minimumInclus && nombre == minimum ) return false;
	if ( nombre > maximum ) return false;
	if ( !maximumInclus && nombre == maximum ) return false;
	return true;
}

/**
* Affiche l'intervalle sous le format ][<minimum>, <maximum>][.
*/
// --------------------------------------------------------------------------
template< typename Nombre >
 ostream & operator << ( ostream & sortie,
	const Intervalle< Nombre > & intervalle )
// --------------------------------------------------------------------------
{
	if ( intervalle.minimumInclus ) sortie << "[";
	else sortie << "]";
	sortie << intervalle.minimum << ".." << intervalle.maximum;
	if ( intervalle.maximumInclus ) sortie << "]";
	else sortie << "[";
	return sortie;
}

template< typename Nombre >
const char * const Intervalle< Nombre >::LimitesIncompatibles::message
	= "le minimum est superieur au maximum.";

/**
*/
// --------------------------------------------------------------------------
template< typename Nombre >
ostream & operator << ( ostream & sortie,
	const Intervalle< Nombre >::LimitesIncompatibles & erreur )
// --------------------------------------------------------------------------
{
	return sortie << "le minimum est superieur au maximum.";
	// return sortie << erreur. message;
}
