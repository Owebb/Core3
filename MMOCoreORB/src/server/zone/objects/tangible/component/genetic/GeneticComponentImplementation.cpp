/*
Copyright (C) 2007 <SWGEmu>

This File is part of Core3.

This program is free software; you can redistribute
it and/or modify it under the terms of the GNU Lesser
General Public License as published by the Free Software
Foundation; either version 2 of the License,
or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Linking Engine3 statically or dynamically with other modules
is making a combined work based on Engine3.
Thus, the terms and conditions of the GNU Lesser General Public License
cover the whole combination.

In addition, as a special exception, the copyright holders of Engine3
give you permission to combine Engine3 program with free software
programs or libraries that are released under the GNU LGPL and with
code included in the standard release of Core3 under the GNU LGPL
license (or modified versions of such code, with unchanged license).
You may copy and distribute such a system following the terms of the
GNU LGPL for Engine3 and the licenses of the other code concerned,
provided that you include the source code of that other code when
and as the GNU LGPL requires distribution of source code.

Note that people who make modified versions of Engine3 are not obligated
to grant this special exception for their modified versions;
it is their choice whether to do so. The GNU Lesser General Public License
gives permission to release a modified version without this exception;
this exception also makes it possible to release a modified version
which carries forward this exception.
*/

#include "GeneticComponent.h"
#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"
#include "server/zone/objects/tangible/weapon/WeaponObject.h"
#include "server/zone/templates/mobile/CreatureTemplate.h"

void GeneticComponentImplementation::initializeTransientMembers() {
	ComponentImplementation::initializeTransientMembers();
}

void GeneticComponentImplementation::updateCraftingValues(CraftingValues* values, bool firstUpdate) {
	ComponentImplementation::updateCraftingValues(values, firstUpdate);
	if (firstUpdate) {
		/**
		 * Now we need to grab the appropiate slots and apply the rules for first pass, vs experimentation.
		 */
	//	addProperty("dna_comp_armor_kinetic",kinResist,10,"@obj_attr_n:dna_comp_armor_kinetic");
	//	addProperty("dna_comp_armor_energy",energyResist,10,"@obj_attr_n:dna_comp_armor_energy");
	//	addProperty("dna_comp_armor_blast",blastResist,10,"@obj_attr_n:dna_comp_armor_blast");
	//	addProperty("dna_comp_armor_heat",heatResist,10,"@obj_attr_n:dna_comp_armor_heat");
	//	addProperty("dna_comp_armor_cold",coldResist,10,"@obj_attr_n:dna_comp_armor_cold");
	//	addProperty("dna_comp_armor_electric",elecResist,10,"@obj_attr_n:dna_comp_armor_electric");
	//	addProperty("dna_comp_armor_acid",acidResist,10,"@obj_attr_n:dna_comp_armor_acid");
	//	addProperty("dna_comp_armor_stun",stunResist,10,"@obj_attr_n:dna_comp_armor_stun");
	} else {

	}
}
String GeneticComponentImplementation::convertSpecialAttack(String &attackName) {
	if (attackName == "defaultattack")
		return "@combat_effects:none";
	else
		return "@combat_effects:" + attackName;
}
String GeneticComponentImplementation::resistValue(float input){
	if (input < 0) {
		return "Vulnerable";
	} else {
		StringBuffer displayvalue;
		displayvalue << Math::getPrecision(input, 10);
		return displayvalue.toString();
	}
}
void GeneticComponentImplementation::fillAttributeList(AttributeListMessage* alm, CreatureObject* object) {
	switch (quality){
		case 1:
			alm->insertAttribute("dna_comp_quality","@obj_attr_n:dna_comp_very_high");
			break;
		case 2:
			alm->insertAttribute("dna_comp_quality","@obj_attr_n:dna_comp_high");
			break;
		case 3:
			alm->insertAttribute("dna_comp_quality","@obj_attr_n:dna_comp_above_average");
			break;
		case 4:
			alm->insertAttribute("dna_comp_quality","@obj_attr_n:dna_comp_average");
			break;
		case 5:
			alm->insertAttribute("dna_comp_quality","@obj_attr_n:dna_comp_below_average");
			break;
		case 6:
			alm->insertAttribute("dna_comp_quality","@obj_attr_n:dna_comp_low");
			break;
		case 7:
			alm->insertAttribute("dna_comp_quality","@obj_attr_n:dna_comp_very_low");
			break;
	}
	ComponentImplementation::fillAttributeList(alm,object);
	if (armorRating == 0)
		alm->insertAttribute("dna_comp_armor_rating","@obj_attr_n:armor_pierce_none");
	else if (armorRating == 1)
		alm->insertAttribute("dna_comp_armor_rating","@obj_attr_n:armor_pierce_light");
	else if (armorRating == 2)
		alm->insertAttribute("dna_comp_armor_rating","@obj_attr_n:armor_pierce_medium");
	else if (armorRating == 3)
		alm->insertAttribute("dna_comp_armor_rating","@obj_attr_n:armor_pierce_none");
	// Add resists
	alm->insertAttribute("dna_comp_armor_kinetic",resistValue(kinResist));
	alm->insertAttribute("dna_comp_armor_energy",resistValue(energyResist));
	alm->insertAttribute("dna_comp_armor_blast",resistValue(blastResist));
	alm->insertAttribute("dna_comp_armor_heat",resistValue(heatResist));
	alm->insertAttribute("dna_comp_armor_cold",resistValue(coldResist));
	alm->insertAttribute("dna_comp_armor_electric",resistValue(elecResist));
	alm->insertAttribute("dna_comp_armor_acid",resistValue(acidResist));
	alm->insertAttribute("dna_comp_armor_stun",resistValue(stunResist));
	alm->insertAttribute("dna_comp_armor_saber",resistValue(saberResist));
	alm->insertAttribute("spec_atk_1",convertSpecialAttack(special1));
	alm->insertAttribute("spec_atk_2",convertSpecialAttack(special2));
	alm->insertAttribute("dna_comp_ranged_attack",ranged ? "Yes" : "No");
}
