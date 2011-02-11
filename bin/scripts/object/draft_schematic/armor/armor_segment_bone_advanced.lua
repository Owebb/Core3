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


object_draft_schematic_armor_armor_segment_bone_advanced = object_draft_schematic_armor_shared_armor_segment_bone_advanced:new {

   templateType = DRAFTSCHEMATIC,

   customObjectName = "Advanced Bone Armor Segment",

   groupName = "craftArmorPersonalGroupC", -- Group schematic is awarded in (See skills table)

   craftingToolTab = 2, -- (See DraftSchemticImplementation.h)
   complexity = 8, 
   size = 4, 

   xpType = "crafting_clothing_armor", 
   xp = 30, 

   assemblySkill = "armor_assembly", 
   experimentingSkill = "armor_experimentation", 
   customizationSkill = "armor_customization", 

   customizationOptions = {},
   customizationStringNames = {},
   customizationDefaults = {},

   ingredientTemplateNames = {"craft_armor_ingredients_n", "craft_armor_ingredients_n", "craft_armor_ingredients_n"},
   ingredientTitleNames = {"armor_segment_bone", "segment_mounting_tabs", "segment_enhancement"},
   ingredientSlotType = {0, 0, 4},
   resourceTypes = {"bone_mammal_rori", "iron_kammris", "object/tangible/component/armor/shared_base_armor_segment_enhancement.iff"},
   resourceQuantities = {23, 6, 1},
   combineTypes = {0, 0, 1},
   contribution = {100, 100, 100},

   numberExperimentalProperties = {1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 2, 1},
   experimentalProperties = {"XX", "XX", "XX", "OQ", "SR", "OQ", "UT", "MA", "OQ", "MA", "OQ", "MA", "OQ", "XX", "XX", "OQ", "SR", "XX"},
   experimentalWeights = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
   experimentalGroupTitles = {"null", "null", "exp_durability", "exp_quality", "exp_durability", "exp_durability", "exp_durability", "exp_durability", "null", "null", "exp_resistance", "null"},
   experimentalSubGroupTitles = {"null", "null", "hit_points", "armor_effectiveness", "armor_integrity", "armor_health_encumbrance", "armor_action_encumbrance", "armor_mind_encumbrance", "armor_rating", "armor_special_type", "armor_special_effectiveness", "armor_special_integrity"},
   experimentalMin = {0, 0, 1000, 1, 100, 6, 8, 4, 1, 2, 1, 100},
   experimentalMax = {0, 0, 1000, 10, 1000, 1, 1, 1, 1, 2, 20, 1000},
   experimentalPrecision = {0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0},

   tanoCRC = 3592675569, -- Script: 'object/tangible/component/armor/armor_segment_bone_advanced.iff'
}
ObjectTemplates:addTemplate(object_draft_schematic_armor_armor_segment_bone_advanced, "object/draft_schematic/armor/armor_segment_bone_advanced.iff")