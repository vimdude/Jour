#include <iostream.h>
#include "Jour.h"
#include "Intervalle.cpp"

void main()
{
	Jour unJour;
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
}