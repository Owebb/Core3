--Copyright (C) 2010 <SWGEmu>


--This File is part of Core3.

--This program is free software; you can redistribute 
--it and/or modify it under the terms of the GNU Lesser 
--General Public License as published by the Free Software
--Foundation; either version 2 of the License, 
--or (at your option) any later version.

--This program is distributed in the hope that it will be useful, 
--but WITHOUT ANY WARRANTY; without even the implied warranty of 
--MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
--See the GNU Lesser General Public License for
--more details.

--You should have received a copy of the GNU Lesser General 
--Public License along with this program; if not, write to
--the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

--Linking Engine3 statically or dynamically with other modules 
--is making a combined work based on Engine3. 
--Thus, the terms and conditions of the GNU Lesser General Public License 
--cover the whole combination.

--In addition, as a special exception, the copyright holders of Engine3 
--give you permission to combine Engine3 program with free software 
--programs or libraries that are released under the GNU LGPL and with 
--code included in the standard release of Core3 under the GNU LGPL 
--license (or modified versions of such code, with unchanged license). 
--You may copy and distribute such a system following the terms of the 
--GNU LGPL for Engine3 and the licenses of the other code concerned, 
--provided that you include the source code of that other code when 
--and as the GNU LGPL requires distribution of source code.

--Note that people who make modified versions of Engine3 are not obligated 
--to grant this special exception for their modified versions; 
--it is their choice whether to do so. The GNU Lesser General Public License 
--gives permission to release a modified version without this exception; 
--this exception also makes it possible to release a modified version 


object_draft_schematic_spices_spice_shadowpaw = object_draft_schematic_spices_shared_spice_shadowpaw:new {

   templateType = DRAFTSCHEMATIC,

   customObjectName = "Shadowpaw",

   groupName = "craftSmugglerSpiceNovice", -- Group schematic is awarded in (See skills table)

   craftingToolTab = 4, -- (See DraftSchemticImplementation.h)
   complexity = 10, 
   size = 1, 

   xpType = "crafting_spice", 
   xp = 120, 

   assemblySkill = "spice_assembly", 
   experimentingSkill = "spice_experimentation", 
   customizationSkill = "spice_customization", 

   customizationOptions = {},
   customizationStringNames = {},
   customizationDefaults = {},

   ingredientTemplateNames = {"craft_food_ingredients_n", "craft_food_ingredients_n"},
   ingredientTitleNames = {"crushed_root", "container"},
   ingredientSlotType = {0, 0},
   resourceTypes = {"organic", "metal"},
   resourceQuantities = {25, 5},
   combineTypes = {0, 0},
   contribution = {100, 100},

   templates = {
              3911095556, -- Script: 'object/tangible/food/spice/spice_shadowpaw.iff'
             }

}
ObjectTemplates:addTemplate(object_draft_schematic_spices_spice_shadowpaw, "object/draft_schematic/spices/spice_shadowpaw.iff")