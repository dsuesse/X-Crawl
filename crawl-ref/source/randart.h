/*
 *  File:       randart.cc
 *  Summary:    Random and unrandom artifact functions.
 *  Written by: Linley Henzell
 *
 *  Change History (most recent first):
 *
 *               <1>     -/--/--        LRH             Created
 */


#ifndef RANDART_H
#define RANDART_H

#include "enum.h"
#include "externs.h"

// used in files.cc, newgame.cc, randart.cc {dlb}
#define NO_UNRANDARTS 53
#define RA_PROPERTIES 30

// Reserving the upper bits for later expansion/versioning.
#define RANDART_SEED_MASK  0x00ffffff


bool is_artefact( const item_def &item );
bool is_random_artefact( const item_def &item );
bool is_unrandom_artefact( const item_def &item );
bool is_fixed_artefact( const item_def &item );

int  get_unique_item_status( int base_type, int type );
void set_unique_item_status( int base_type, int type, int status );

/* ***********************************************************************
 * called from: itemname
 * *********************************************************************** */
const char *randart_armour_name( const item_def &item );

/* ***********************************************************************
 * called from: itemname
 * *********************************************************************** */
const char *randart_name( const item_def &item );

/* ***********************************************************************
 * called from: itemname
 * *********************************************************************** */
const char *randart_jewellery_name( const item_def &item );

/* ***********************************************************************
 * called from: describe
 * *********************************************************************** */
const char *unrandart_descrip( char which_descrip, const item_def &item );

bool does_unrandart_exist(int whun);

/* ***********************************************************************
 * called from: dungeon
 * *********************************************************************** */
int find_okay_unrandart(unsigned char aclass, unsigned char atype = OBJ_RANDOM);

typedef FixedVector< int, RA_PROPERTIES > randart_properties_t;

/* ***********************************************************************
 * called from: describe - fight - it_use2 - item_use - player
 * *********************************************************************** */
void randart_wpn_properties( const item_def &item, 
                             randart_properties_t &proprt );

int randart_wpn_property( const item_def &item, int prop );


/* ***********************************************************************
 * called from: dungeon
 * *********************************************************************** */
bool make_item_fixed_artefact( item_def &item, bool in_abyss, int which = 0 );

bool make_item_randart( item_def &item );
bool make_item_unrandart( item_def &item, int unrand_index );

/* ***********************************************************************
 * called from: files - newgame
 * *********************************************************************** */
void set_unrandart_exist(int whun, bool is_exist);

/* ***********************************************************************
 * called from: items
 * *********************************************************************** */
int find_unrandart_index(int item_index);

#endif
