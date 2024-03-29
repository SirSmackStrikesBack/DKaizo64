#include "../include/common.h"

static const u8 bad_maps[] = {
	1, // Funky's Store
	2, // DK Arcade
	3, // K. Rool Barrel: Lanky's Maze
	4, // Jungle Japes: Mountain
	5, // Cranky's Lab
	6, // Jungle Japes: Minecart
	9, // Jetpac
	10, // Kremling Kosh! (very easy)
	12, // Jungle Japes: Shell
	13, // Lanky's Cave
	14, // Angry Aztec: Beetle Race // Note: Softlock at the end if enabled?
	15, // Snide's H.Q.
	18, // Teetering Turtle Trouble! (very easy)
	19, // Angry Aztec: 5 Door Temple DK
	21, // Angry Aztec: 5 Door Temple Diddy
	22, // Angry Aztec: 5 Door Temple Tiny
	23, // Angry Aztec: 5 Door Temple Lanky
	24, // Angry Aztec: 5 Door Temple Chunky
	25, // Candy's Music Shop
	27, // Frantic Factory: Car Race
	29, // Power Shed
	31, // Gloomy Galleon: K. Rool's Ship 
	32, // Batty Barrel Bandit! (easy)
	35, // K. Rool Barrel: DK's Target Game
	37, // Jungle Japes: Barrel Blast // Note: The barrels don't work as other kongs so not much point enabling it on this map
	39, // Gloomy Galleon: Seal Race
	41, // Angry Aztec: Barrel Blast
	43, // Gloomy Galleon: Diddy/Lanky/Chunky 5 Door Ship
	44, // Gloomy Galleon: Treasure Chest
	45, // Gloomy Galleon: Mermaid
	46, // Gloomy Galleon: Tiny/DK 5 Door Ship
	47, // Gloomy Galloen: 2 Door Ship
	49, // Gloomy Galleon: Lighthouse
	50, // K. Rool Barrel: Tiny's Mushroom Game
	52, // Fungi Forest: Ant Hill
	54, // Gloomy Galleon: Barrel Blast
	55, // Fungi Forest: Minecart
	56, // Fungi Forest: Diddy's Barn
	57, // Fungi Forest: Diddy's Attic
	59, // Fungi Forest: DK's Barn
	60, // Fungi Forest: Spider
	62, // Fungi Forest: Rear of Mill
	63, // Fungi Forest: Mushroom Puzzle
	70, // Fungi Forest: Mushroom Leap
	71, // Fungi Forest: Shooting Game
	76, // DK Rap
	77, // Minecart Mayhem! (easy)
	78, // Busy Barrel Barrage! (easy)
	79, // Busy Barrel Barrage! (normal)
	80, // Main Menu
	82, // Crystal Caves: Beetle Race
	83, // Fungi Forest: Dogadon
	89, // Crystal Caves: Rotating Room
	90, // Crystal Caves: DK 5 Door Cabin
	92, // Crystal Caves: Diddy Middle 5 Door Cabin
	93, // Crystal Caves: Tiny 5 Door Cabin
	94, // Crystal Caves: Lanky Cabin
	95, // Crystal Caves: Chunky Igloo
	98, // Crystal Caves: Ice Castle
	101, // Krazy Kong Klamour! (easy) // Note: Broken with switch kong
	102, // Big Bug Bash! (very easy) // Note: Broken with switch kong
	103, // Searchlight Seek! (very easy) // Note: Broken with switch kong
	104, // Beaver Bother! (easy) // Note: Broken with switch kong
	106, // Creepy Castle: Minecart
	107, // Kong Battle: Battle Arena // TODO: Would be really cool to get multiplayer working, currently just voids you out when activated
	109, // Kong Battle: Arena 1 // TODO: Would be really cool to get multiplayer working, currently just voids you out when activated
	110, // Frantic Factory: Barrel Blast
	111, // Gloomy Galleon: Puftoss
	113, // Creepy Castle: Museum
	114, // Creepy Castle: Library
	115, // Kremling Kosh! (easy)
	116, // Kremling Kosh! (normal)
	117, // Kremling Kosh! (hard)
	118, // Teetering Turtle Trouble! (easy)
	119, // Teetering Turtle Trouble! (normal)
	120, // Teetering Turtle Trouble! (hard)
	121, // Batty Barrel Bandit! (easy)
	122, // Batty Barrel Bandit! (normal)
	123, // Batty Barrel Bandit! (hard)
	131, // Busy Barrel Barrage! (hard)
	136, // Beaver Bother! (normal)
	137, // Beaver Bother! (hard)
	138, // Searchlight Seek! (easy)
	139, // Searchlight Seek! (normal)
	140, // Searchlight Seek! (hard)
	141, // Krazy Kong Klamour! (normal)
	142, // Krazy Kong Klamour! (hard)
	143, // Krazy Kong Klamour! (insane)
	144, // Peril Path Panic! (very easy) // Note: Broken with switch kong
	145, // Peril Path Panic! (easy)
	146, // Peril Path Panic! (normal)
	147, // Peril Path Panic! (hard)
	148, // Big Bug Bash! (easy)
	149, // Big Bug Bash! (normal)
	150, // Big Bug Bash! (hard)
	152, // Hideout Helm (Intro Story) // Note: Handled by cutscene check
	153, // DK Isles (DK Theatre) // Note: Handled by cutscene check
	165, // K. Rool Barrel: Diddy's Kremling Game
	166, // Creepy Castle: Chunky's Toolshed
	167, // Creepy Castle: Trash Can
	168, // Creepy Castle: Greenhouse
	172, // Rock (Intro Story) // Note: Handled by cutscene check
	179, // Gloomy Galleon: Submarine
	184, // Enguarde Arena // Note: Handled by character check // Mislabeled
	185, // Creepy Castle: Car Race
	186, // Crystal Caves: Barrel Blast
	187, // Creepy Castle: Barrel Blast
	188, // Fungi Forest: Barrel Blast
	189, // Fairy Island
	190, // Kong Battle: Arena 2 // TODO: Would be really cool to get multiplayer working, currently just voids you out when activated
	191, // Rambi Arena // Note: Handled by character check
	192, // Kong Battle: Arena 3 // Mislabeled?
	196, // Crystal Caves: Army Dillo
	197, // Angry Aztec: Dogadon
	198, // Training Grounds (End Sequence) // Note: Handled by cutscene check
	199, // Creepy Castle: King Kut Out // Note: Doesn't break the kong order but since this fight is explicitly about tagging we might as well disable
	200, // Crystal Caves: Diddy's Upper 5 Door Cabin
	201, // K. Rool Barrel: Diddy's Rocketbarrel Game
	202, // K. Rool Barrel: Lanky's Shooting Game
	203, // K. Rool Fight: DK Phase // Note: Enabling here breaks the fight and may cause softlocks
	204, // K. Rool Fight: Diddy Phase // Note: Enabling here breaks the fight and may cause softlocks
	205, // K. Rool Fight: Lanky Phase // Note: Enabling here breaks the fight and may cause softlocks
	206, // K. Rool Fight: Tiny Phase // Note: Enabling here breaks the fight and may cause softlocks
	207, // K. Rool Fight: Chunky Phase // Note: Enabling here breaks the fight and may cause softlocks
	208, // Bloopers Ending // Note: Handled by cutscene check
	209, // K. Rool Barrel: Chunky's Hidden Kremling Game
	210, // K. Rool Barrel: Tiny's Pony Tail Twirl Game
	211, // K. Rool Barrel: Chunky's Shooting Game
	212, // K. Rool Barrel: DK's Rambi Game
	213, // K. Lumsy Ending // Note: Handled by cutscene check
	214, // K. Rool's Shoe
	215, // K. Rool's Arena // Note: Handled by cutscene check?
};

static const u8 bad_movement_states[] = {
	//0x02, // First Person Camera
	//0x03, // First Person Camera (Water)
	0x04, // Fairy Camera
	0x05, // Fairy Camera (Water)
	0x06, // Locked (Bonus Barrel)
	0x15, // Slipping
	0x16, // Slipping
	0x18, // Baboon Blast Pad
	0x1B, // Simian Spring
	//0x1C, // Simian Slam // Note: As far as I know this doesn't break anything, so we'll save the CPU cycles
	0x20, // Falling/Splat, // Note: Prevents quick recovery from fall damage, and I guess maybe switching to avoid fall damage?
	0x2D, // Shockwave
	0x2E, // Chimpy Charge
	0x31, // Damaged
	0x32, // Stunlocked
	0x33, // Damaged
	0x35, // Damaged
	0x36, // Death
	0x37, // Damaged (Underwater)
	0x38, // Damaged
	0x39, // Shrinking
	0x42, // Barrel
	0x43, // Barrel (Underwater)
	0x44, // Baboon Blast Shot
	0x45, // Cannon Shot
	0x52, // Bananaporter
	0x53, // Monkeyport
	0x54, // Bananaporter (Multiplayer)
	0x56, // Locked
	0x57, // Swinging on Vine
	0x58, // Leaving Vine
	0x59, // Climbing Tree
	0x5A, // Leaving Tree
	0x5B, // Grabbed Ledge
	0x5C, // Pulling up on Ledge
	0x63, // Rocketbarrel // Note: Covered by crystal HUD check except for Helm & K. Rool
	0x64, // Taking Photo
	0x65, // Taking Photo
	0x67, // Instrument
	0x69, // Car
	0x6A, // Learning Gun // Note: Handled by map check
	0x6B, // Locked
	0x6C, // Feeding T&S // Note: Handled by map check
	0x6D, // Boat
	0x6E, // Baboon Balloon
	0x6F, // Updraft
	0x70, // GB Dance
	0x71, // Key Dance
	0x72, // Crown Dance
	0x73, // Loss Dance
	0x74, // Victory Dance
	0x78, // Gorilla Grab
	0x79, // Learning Move // Note: Handled by map check
	0x7A, // Locked
	0x7B, // Locked
	0x7C, // Trapped (spider miniBoss)
	0x7D, // Klaptrap Kong (beaver bother) // Note: Handled by map check
	0x83, // Fairy Refill
	0x87, // Entering Portal
	0x88, // Exiting Portal
};

static const u16 speedrun_mode_permanent_flags[] = {
	367, // Diddy FTT
	368, // Lanky FTT
	385, // Kong Unlocked: DK
	369, // Tiny FTT
	370, // Chunky FTT
	42, // Japes: Cutscene by far W1 played // Diddy's help me cutscene
	93, // Aztec: Lanky's help me cutscene
	94, // Aztec: Tiny's help me cutscene
	140, // Factory: Chunky's help me cutscene
	384, // Cranky's Lab Simian Slam Tutorial
	27, // Japes: Cutscene at the start played
	95, // Aztec: FT Cutscene
	92, // Aztec: Llama Cutscene
	194, // Galleon: First Time Cutscene
	257, // Fungi: First Time Cutscene
	282, // Caves: First Time Cutscene
	299, // Caves: Giant Kosha Cutscene
	349, // Castle: First Time Cutscene
	355, // Bananaporter FTT
	356, // Japes: Baboon Blast Cranky CS
	358, // Crown Pad FTT
	359, // T&S FTT (1)
	360, // Mini Monkey FTT
	361, // Hunky Chunky FTT
	362, // Orangstand Sprint FTT
	363, // Strong Kong FTT
	364, // Rainbow Coin FTT
	365, // Rambi FTT
	366, // Enguarde FTT
	372, // Snide's FTT
	376, // Wrinkly FTT
	378, // Training Grounds: Treehouse Squawks Cutscene
	382, // B. Locker FTT
	383, // Training Grounds: Barrels Spawned
	386, // Training Grounds: Dive Barrel Completed
	387, // Vine Barrel
	388, // Training Grounds: Orange Barrel Completed
	389, // Training Grounds: Barrel Barrel Completed
	390, // Isles: Escape Cutscene
	391, // Training Grounds: All Training Barrels Complete CS
};

static const u16 speedrun_mode_temporary_flags[] = {
	104, // Japes: Army Dillo Long Intro
	103, // Aztec: Dogadon Long Intro
	106, // Factory: Mad Jack Long Intro
	107, // Galleon: Puftoss Long Intro
	105, // Fungi: Dogadon Long Intro
	109, // Caves: Army Dillo Long Intro
	108, // Castle: Kut Out Long Intro
	101, // Caves: Beetle FT Long Intro
	102, // Aztec: Beetle FT Long Intro
};

static const u16 kong_unlocked_flags[] = {
	385, // Kong Unlocked: DK
	6, // Kong Unlocked: Diddy
	70, // Kong Unlocked: Lanky
	66, // Kong Unlocked: Tiny
	117, // Kong Unlocked: Chunky
};

static s32 inBadMapIndex = 0;
static s32 inBadMapCache = 0;
static u16 parentMapCache = 0;
static s32 storySkipLoaded = 0;

s32 inBadMap(void) {
	if (inBadMapIndex == CurrentMap) {
		return inBadMapCache;
	}
	inBadMapCache = 0;
	inBadMapIndex = CurrentMap;
	for (s32 i = 0; i < sizeof(bad_maps) / sizeof(bad_maps[0]); i++) {
		if (CurrentMap == bad_maps[i]) {
			inBadMapCache = 1;
			break;
		}
	}
	return inBadMapCache;
}

s32 inBadMovementState(void) {
	if (Player) {
		for (s32 i = 0; i < sizeof(bad_movement_states) / sizeof(bad_movement_states[0]); i++) {
			if (Player->control_state == bad_movement_states[i]) {
				return 1;
			}
		}
		// Check for gorilla gone in effect bitfield
		if (Player->strong_kong_ostand_bitfield & 0x40) {
			return 1;
		}
	}
	return 0;
}

void tagDenied() {
	if (NewlyPressedControllerInput.Buttons & R_JPAD || NewlyPressedControllerInput.Buttons & L_TRIG) {
		playSound(152, 0x2FFF, 63.0f, 1.0f, 0, 0);
	} else if (NewlyPressedControllerInput.Buttons & L_JPAD) {
		playSound(152, 0x2FFF, 63.0f, 1.0f, 0, 0);
	}
}

void tagAnywhere(void) {
	s32 _dest_character;
	s32 tagDirection;
	s8* Snide;

	// Main Menu
	if (CurrentMap == 80) {
		// Remember Story Skip option through resets
		if (!storySkipLoaded) {
			StorySkip = checkFlag(35, 1);
			storySkipLoaded = 1;
		} else {
			setFlag(35, StorySkip, 1);
		}
			// Start the player in DK Isles instead of Training Grounds
			*(s8 *)(0x80714547) = 34;
			*(s8 *)(0x8071455B) = 0;

			// Make T&S feeding faster
			*(u32 *)(0x806BE3E0) = 0;

			// Enable K. Lumsy cutscene compression
			*(u32 *)(0x806BDC98) = 0;

			// Set temporary flags
			for (s32 i = 0; i < sizeof(speedrun_mode_temporary_flags) / sizeof(speedrun_mode_temporary_flags[0]); i++) {
				setFlag(speedrun_mode_temporary_flags[i], 1 , 2);
			}
			// Set permanent flags
			for (s32 i = 0; i < sizeof(speedrun_mode_permanent_flags) / sizeof(speedrun_mode_permanent_flags[0]); i++) {
				setFlag(speedrun_mode_permanent_flags[i], 1, 0);
			}

	}

	// Snide's HQ
	if (CurrentMap == 15) {
		if (StorySkip) {
			// Snide's cutscene compression
			// The cutscene the game chooses is based on the parent map (the method used to detect which Snide's H.Q. you're in)
			// The shortest contraption cutscene is chosen with parent map 0
			// So we swap out the original parent map with 0 at the right moment to get short cutscenes
			// Then swap the original value back in at the right moment so that the player isn't taken back to test map when exiting Snide's H.Q.
			if (CutsceneIndex == 5) {
				if (CutsceneTimer == 199) {
					// Make a backup copy of the current parent map to restore later
					parentMapCache = ParentMap;
				} else if (CutsceneTimer == 200) {
					ParentMap = 0;
				}
			} else if (CutsceneIndex == 2) {
				// Restore the backup copy of the parent map
				ParentMap = parentMapCache;
			}

			// Snide turn in compression
			Snide = findActorWithType(184);
			if (Snide) {
				// Read the turn count (Snide + 0x232)
				if (Snide[0x232] != 0) {
					Snide[0x232] = 1;
				}
			}
		}
	}

	// Skip GB/Key dances
		switch (CurrentMap) {
			// Disable dance skips on the following maps
			// If these are enabled, pause + exit is required to leave the map after collecting the GB
			case 14: // Aztec Beetle Race
			case 27: // Factory Car Race
			case 39: // Galleon Seal Race
			case 82: // Caves Beetle Race
			case 185: // Castle Car Race
				// Don't skip GB dances
				*(u32 *)(0x806EFB9C) = 0xA1EE0154; // Enable Movement Write
				*(u32 *)(0x806EFC1C) = 0x0C189E52; // Enable CS Play Function Call
				*(u32 *)(0x806EFB88) = 0x0C18539E; // Enable Animation Write Function Call
				*(u32 *)(0x806EFC0C) = 0xA58200E6; // Enable Change Rotation Write
				*(u32 *)(0x806EFBA8) = 0xA3000155; // Enable Control State Progress Zeroing
				break;
			default:
				// Skip GB dances
				*(u32 *)(0x806EFB9C) = 0; // Cancel Movement Write
				*(u32 *)(0x806EFC1C) = 0; // Cancel CS Play Function Call
				*(u32 *)(0x806EFB88) = 0; // Cancel Animation Write Function Call
				*(u32 *)(0x806EFC0C) = 0; // Cancel Change Rotation Write
				*(u32 *)(0x806EFBA8) = 0; // Cancel Control State Progress Zeroing
		}

	// Map is loading
	if (LZFadeoutProgress > 0) {
		tagDenied();
		return;
	}
	// In tag barrel / paused
	if (TBVoidByte & 2) {
		tagDenied();
		return;
	}
	if (IsAutowalking) {
		tagDenied();
		return;
	}
	if (CutsceneActive) {
		tagDenied();
		return;
	}
	if (inBadMap()) {
		tagDenied();
		return;
	}
	// Don't allow tagging when HUD is open
	if (HUD) {
		// Coloured Banana
		if (HUD[0].hud_state) {
			tagDenied();
			return;
		}
		// Banana Coin
		if (HUD[1].hud_state) {
			tagDenied();
			return;
		}
		// Crystal Coconut
		if (HUD[5].hud_state) {
			tagDenied();
			return;
		}
		// GB Count (Character)
		// Note: We can't add the bottom counter because it's always shown in lobbies
		if (HUD[8].hud_state) {
			tagDenied();
			return;
		}
		// Banana Medal
		if (HUD[10].hud_state) {
			tagDenied();
			return;
		}
		// Blueprint
		if (HUD[12].hud_state) {
			tagDenied();
			return;
		}
		// Coloured Banana?
		if (HUD[13].hud_state) {
			tagDenied();
			return;
		}
		// Banana Coin?
		if (HUD[14].hud_state) {
			tagDenied();
			return;
		}
	}
	if (inBadMovementState()) {
		tagDenied();
		return;
	}
	if (Character > 4) {
		tagDenied();
		return;
	}

	if (NewlyPressedControllerInput.Buttons & R_JPAD || NewlyPressedControllerInput.Buttons & L_TRIG) {
		tagDirection = 1;
	} else if (NewlyPressedControllerInput.Buttons & L_JPAD) {
		tagDirection = -1;
	} else {
		return;
	}

	_dest_character = Character + tagDirection;
	while (7) {
		// Wrap from DK to Chunky
		if (_dest_character < 0) {
			_dest_character = 4;
		}
		// Wrap from Chunky to DK
		if (_dest_character > 4) {
			_dest_character = 0;
		}

		// DK can always be tagged
		if (_dest_character == 0) {
			break;
		}
		// Check whether kong has been unlocked before allowing tag to them
		if (checkFlag(kong_unlocked_flags[_dest_character], 0)) {
			break;
		}
		_dest_character += tagDirection;
	}

	// Without this, a choppy animation occurs if you tag DK -> DK
	if (_dest_character == Character) {
		tagDenied();
		return;
	}

	if (Player) {
		// If the destination kong hasn't bought their gun, or if the current kong does not have their gun out
		if (((MovesBase[_dest_character].weapon_bitfield & 1) == 0) || (Player->was_gun_out == 0)) {
			Player->hand_state = 1;
			Player->was_gun_out = 0;
			// Without this, tags to and from Diddy mess up
			if (_dest_character == 1) {
				Player->hand_state = 0;
			}
		} else {
			Player->hand_state = 2;
			Player->was_gun_out = 1;
			// Without this, tags to and from Diddy mess up
			if (_dest_character == 1) {
				Player->hand_state = 3;
			}
		};
		Player->new_kong = _dest_character + 2;
		if (SwapObject) {
			SwapObject->action_type = 0x3B;
		}
		// Play successful tag SFX
		if (_dest_character == 0) {
			playSound(560, 0x4FFF, 63.0f, 1.0f, 0, 0);
		} else if (_dest_character == 1) {
			playSound(103, 0x4FFF, 63.0f, 1.0f, 0, 0);
		} else if (_dest_character == 2) {
			playSound(218, 0x4FFF, 63.0f, 1.0f, 0, 0);
		} else if (_dest_character == 3) {
			playSound(182, 0x4FFF, 63.0f, 1.0f, 0, 0);
		} else if (_dest_character == 4) {
			playSound(198, 0x4FFF, 63.0f, 1.0f, 0, 0);
		}
	}
}

