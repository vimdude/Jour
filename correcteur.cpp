/* -+----1----+----2----+----3----+----4----+----5----+----6----+----7----+- */
/* ========================================================================= */
/*                               correcteur.cpp                              */
/* ========================================================================= */
/*                                                                           */
/* Correcteur de la classe EntierBorne.                                      */
/*                                                                           */
/* ========================================================================= */

#include <iostream.h>
#include <fstream.h>
#include <exception>
#include <stdio.h>
#include <string.h>

#include "Intervalle.cpp"
#include "Jour.h"

static void rapporter( ofstream &correction, char *message );

// ----------------------------------------------------------------------------
int main( int nombreDArguments, char *arguments[ ] )
// ----------------------------------------------------------------------------
{
	char *nomDuFichierDeCorrection = "correction.txt";
	if ( nombreDArguments == 2 ) {
		nomDuFichierDeCorrection = arguments[ 1 ];
	}
	ofstream correction = ofstream( nomDuFichierDeCorrection, ios::out );
	if ( correction == 0 ) {
		cerr << "Echec de l'ouverture de \"" << nomDuFichierDeCorrection
			<< "\"" << endl;
		return 1;
	}

	/* ----------------------------- service --------------------------------- */

	char message[ 1024 ];
	double valeur;
	bool continuer = true;
	double noteMax = 0.0;
	double note = 0.0;
	unsigned int numeroDeTest = 0;

	Jour unJour;
	Jour hier;

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( unJour != 0 ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) fournirMinimum( ) d'un jour implicite devrait\n",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				"etre 0.\n" );
			rapporter( correction, message );
		}
	}

	hier = unJour++;

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( unJour != 1 ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) l'operateur ++ ( int ) sur dimanche devrait donner lundi.\n",
				numeroDeTest );
			rapporter( correction, message );
		}
	}

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( hier != 0 ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) l'operateur ++ ( int ) devrait renvoyer le jour original.\n",
				numeroDeTest );
			rapporter( correction, message );
		}
	}

	const Jour samedi( "samedi" );

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( samedi != 6 ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) Le constructeur Jour( const char * const ) est errone.",
				numeroDeTest );
			rapporter( correction, message );
		}
	}

	const Jour mercredi( 3 );

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( mercredi != 3 ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) le jour 3 est un mercredi, constructeur Jour( int ) errone.",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				" donner dimanche.\n" );
			rapporter( correction, message );
		}
	}

	const Jour jeudi( 11 );

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( jeudi != 4 ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) le jour 4 est un jeudi, constructeur Jour( int ) errone.",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				" donner dimanche.\n" );
			rapporter( correction, message );
		}
	}



	const Jour dimanche( "dimanche" );
	unJour = samedi;
	unJour++;

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( unJour != dimanche ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) l'operateur ++ ( int ) applique a samedi devrait",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				" donner dimanche.\n" );
			rapporter( correction, message );
		}
	}

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( unJour != dimanche ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) l'operateur ++ ( int ) applique a samedi devrait",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				" donner dimanche.\n" );
			rapporter( correction, message );
		}
	}

	Jour vendredi( "vendredi" );
	Intervalle< Jour > ouvrables( "lundi", vendredi );
	const Jour lundi( "lundi" );

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( ouvrables.fournirMinimum( ) != lundi ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) fournirMinimum de [lundi..vendredi] devrait",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				" renvoyer lundi.\n" );
			rapporter( correction, message );
		}
	}


	unJour = mercredi;

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( !ouvrables.inclus( unJour )) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) dimanche ne fait pas partie des jours ouvrables.",
				numeroDeTest );
			rapporter( correction, message );
		}
	}

	unJour = mercredi + 2;

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( unJour != vendredi ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) mercredi + 2 devrait donner vendredi.",
				numeroDeTest );
			rapporter( correction, message );
		}
	}

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( samedi - mercredi != 3 ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) samedi - mercredi devrait valoir 3.",
				numeroDeTest );
			rapporter( correction, message );
		}
	}

	Jour jourFutur( mercredi + 18 );

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( jourFutur != dimanche ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) mercredi + 18 devrait valoir dimanche .",
				numeroDeTest );
			rapporter( correction, message );
		}
	}


	/*
	Intervalle< Jour > intervalleJourImplicite;
	cout << "intervalleJourImplicite = " << intervalleJourImplicite << endl;
	Jour lundi( 15 );
	cout << "lundi : " << lundi << endl;
	Jour vendredi( "vendredi" );
	cout << "vendredi: " << vendredi << endl;

	Intervalle< Jour > ouvrables( "lundi", vendredi ); 
	cout << "ouvrables = " << ouvrables << endl;
	Jour mardi( lundi + 8 );
	cout << "mardi : " << mardi << endl;
	if ( ouvrables.inclus( mardi ))
		cout << "le magasin est ouvert." << endl;
	else
		cout << "le magasin est ferme." << endl;
	Jour mercredi = mardi + 15;
	cout << "mercredi: " << mercredi << endl;
	int difference = mercredi - mardi;
	cout << " difference = " << difference << endl;
	ouvrables.modifierMaximumInclus( false );
	cout << "ouvrables = " << ouvrables << endl;
	*/


	/*
	* test des limites d'un EntierBorne implicite.
	*/
	/*
	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( unite.fournirMinimum( ) != 0 ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) fournirMinimum( ) d'un EntierBorne implicite devrait\n",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				"etre 0.\n" );
			rapporter( correction, message );
		}
	}
	*/
	



	/* ----------------------------- service --------------------------------- */
	note += noteMax;
	note = note/noteMax;
	sprintf( message, "note obtenue: %6.2lf.\n", note );
	rapporter( correction, message );
	return 0;
}

/* ------------------------------------------------------------------------- */
static void rapporter( ofstream &correction, char *message )
/* ------------------------------------------------------------------------- */
{
	correction << message << flush;
	cout << message << flush;
} 
