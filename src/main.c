#include "../include/common.h"

static unsigned int S = 0;
static unsigned int C = 0;


int crown_maps[] = {0x35, 0x49, 0x9B, 0x9C, 0x9F, 0x9E, 0x9D, 0xA0, 0xA1, 0xA2};
int boss_maps[] = {0x08, 0xC5, 0xAF, 0x6F, 0x53, 0xC4, 0xC7};
int crown_flags[] = {609, 610, 611, 612, 613, 614, 615, 616, 617, 618};
int boss_flags[] = {26, 74, 138, 168, 236, 292, 317};
int crown_exits[] = {17, 1, 0, 0, 0, 0, 2, 0, 0, 0};

int SaveMap = 0;
int SaveExit = 0;

void CheckPoint() {
S = 300; // Resets Helm timer
for (int i = 0; i < 40; i++) {if(checkFlag(469 + i, TYPE_PERMANENT) == 1) {setFlag(509 + i, 1, TYPE_PERMANENT);};}; // Turns in collected blueprints (resetting BP time bonus to zero)
Save(); // Saves the game
};

void cFuncLoop(void) {
	
	// Enable stack trace upon crash
	*(s8 *)(0x807563B4) = 1;
	*(s32 *)(0x80731F78) = 0;
	/*
		This function is run every frame. Place c code which you are wanting to be run every frame
	*/

	// Disables vanilla "save" function unless Blast-o-Matic is off
	if(checkFlag(770, TYPE_PERMANENT) == 0) {*(int*)(0x8063FBC0) = 0; *(int*)(0x806F5888) = 0; *(int*)(0x80712EC4) = 0; if(CurrentMap == 0x01 || CurrentMap == 0x05 || CurrentMap == 0x19) {*(int*)(0x80025F9C) = 0;};};
	
	// Sets up "checkpoints" at Battle Crowns & Keys
	// if((CurrentMap == 0x35) && (checkFlag(609, TYPE_PERMANENT) == 1)) {CheckPoint();};
	// for (int i = 0; i < 17; i++) {if((CurrentMap == checkpoint_maps[i]) && (checkFlag(checkpoint_flags[i], TYPE_PERMANENT) == 1)) {CheckPoint();};};
	// for (int i = 0; i < 10; i++) {if(CurrentMap == crown_maps[i] && checkFlag(crown_flags[i], TYPE_PERMANENT) == 1){SaveMap = ParentMap; SaveExit = crown_exits[i]; CheckPoint();};}
	for (int i = 0; i < 7; i++) {if(CurrentMap == boss_maps[i] && checkFlag(boss_flags[i], TYPE_PERMANENT) == 1){findTiedParentMap(&SaveMap, &SaveExit); CheckPoint();};}
	MovesBase[0].unk_05 = SaveMap;
	MovesBase[1].unk_05 = SaveExit;
	if(CurrentMap == 80) {
	if(MovesBase[0].unk_05 == 0)
	{DestMap = 34; DestExit = 0;} 
	else {DestMap = MovesBase[0].unk_05; DestExit = MovesBase[1].unk_05;};};

	// Sets up "checkpoints" at Nintendo & Rareware coins
	// if(checkFlag(132, TYPE_PERMANENT) == 1 && checkFlag(801, TYPE_PERMANENT) == 0) {CheckPoint(), setFlag(801, 1, TYPE_PERMANENT);};
	// if(checkFlag(379, TYPE_PERMANENT) == 1 && checkFlag(802, TYPE_PERMANENT) == 0) {CheckPoint(), setFlag(802, 1, TYPE_PERMANENT);};
		

	// Helm Timer Setup
	int B = 180*(checkFlag(469, TYPE_PERMANENT) + checkFlag(470, TYPE_PERMANENT) + checkFlag(471, TYPE_PERMANENT) + checkFlag(472, TYPE_PERMANENT)
	+ checkFlag(473, TYPE_PERMANENT) + checkFlag(474, TYPE_PERMANENT) + checkFlag(475, TYPE_PERMANENT) + checkFlag(476, TYPE_PERMANENT)
	+ checkFlag(477, TYPE_PERMANENT) + checkFlag(478, TYPE_PERMANENT) + checkFlag(479, TYPE_PERMANENT) + checkFlag(480, TYPE_PERMANENT)
	+ checkFlag(481, TYPE_PERMANENT) + checkFlag(482, TYPE_PERMANENT) + checkFlag(483, TYPE_PERMANENT) + checkFlag(484, TYPE_PERMANENT)
	+ checkFlag(485, TYPE_PERMANENT) + checkFlag(486, TYPE_PERMANENT) + checkFlag(487, TYPE_PERMANENT) + checkFlag(488, TYPE_PERMANENT)	
	+ checkFlag(489, TYPE_PERMANENT) + checkFlag(490, TYPE_PERMANENT) + checkFlag(491, TYPE_PERMANENT) + checkFlag(492, TYPE_PERMANENT)
	+ checkFlag(493, TYPE_PERMANENT) + checkFlag(494, TYPE_PERMANENT) + checkFlag(495, TYPE_PERMANENT) + checkFlag(496, TYPE_PERMANENT)
	+ checkFlag(497, TYPE_PERMANENT) + checkFlag(498, TYPE_PERMANENT) + checkFlag(499, TYPE_PERMANENT) + checkFlag(500, TYPE_PERMANENT)
	+ checkFlag(501, TYPE_PERMANENT) + checkFlag(502, TYPE_PERMANENT) + checkFlag(503, TYPE_PERMANENT) + checkFlag(504, TYPE_PERMANENT)
	+ checkFlag(505, TYPE_PERMANENT) + checkFlag(506, TYPE_PERMANENT) + checkFlag(507, TYPE_PERMANENT) + checkFlag(508, TYPE_PERMANENT)
 	- checkFlag(509, TYPE_PERMANENT) - checkFlag(510, TYPE_PERMANENT) - checkFlag(511, TYPE_PERMANENT) - checkFlag(512, TYPE_PERMANENT)
	- checkFlag(513, TYPE_PERMANENT) - checkFlag(514, TYPE_PERMANENT) - checkFlag(515, TYPE_PERMANENT) - checkFlag(516, TYPE_PERMANENT)
	- checkFlag(517, TYPE_PERMANENT) - checkFlag(518, TYPE_PERMANENT) - checkFlag(519, TYPE_PERMANENT) - checkFlag(520, TYPE_PERMANENT)
	- checkFlag(521, TYPE_PERMANENT) - checkFlag(522, TYPE_PERMANENT) - checkFlag(523, TYPE_PERMANENT) - checkFlag(524, TYPE_PERMANENT)
	- checkFlag(525, TYPE_PERMANENT) - checkFlag(526, TYPE_PERMANENT) - checkFlag(527, TYPE_PERMANENT) - checkFlag(528, TYPE_PERMANENT)
	- checkFlag(529, TYPE_PERMANENT) - checkFlag(530, TYPE_PERMANENT) - checkFlag(531, TYPE_PERMANENT) - checkFlag(532, TYPE_PERMANENT)
	- checkFlag(533, TYPE_PERMANENT) - checkFlag(534, TYPE_PERMANENT) - checkFlag(535, TYPE_PERMANENT) - checkFlag(536, TYPE_PERMANENT)
	- checkFlag(537, TYPE_PERMANENT) - checkFlag(538, TYPE_PERMANENT) - checkFlag(539, TYPE_PERMANENT) - checkFlag(540, TYPE_PERMANENT)
	- checkFlag(541, TYPE_PERMANENT) - checkFlag(542, TYPE_PERMANENT) - checkFlag(543, TYPE_PERMANENT) - checkFlag(544, TYPE_PERMANENT)
	- checkFlag(545, TYPE_PERMANENT) - checkFlag(546, TYPE_PERMANENT) - checkFlag(547, TYPE_PERMANENT) - checkFlag(548, TYPE_PERMANENT));
	if(CurrentMap == 0x50) {S = 300;};
	HelmStartTime = S + B;
	
	if((CurrentMap == 3) // Helm barrel
	|| (CurrentMap == 7) // Japes
	|| (CurrentMap == 17) // Helm
	|| (CurrentMap == 20) // Llama Temple
	|| (CurrentMap == 26) // Factory 
	|| (CurrentMap == 30) // Galleon
	|| (CurrentMap == 34) // Isles
	|| (CurrentMap == 35) // Helm barrel
	|| (CurrentMap == 38) // Aztec
	|| (CurrentMap == 42) // T&S
	|| (CurrentMap == 48) // Fungi
	|| (CurrentMap == 50) // Helm barrel
	|| (CurrentMap == 61) // Front Mill
	|| (CurrentMap == 62) // Rear Mill
	|| (CurrentMap == 64) // Giant Mushroom
	|| (CurrentMap == 72) // Caves
	|| (CurrentMap == 87) // Castle
	|| (CurrentMap == 97) // K Lumsy
	|| (CurrentMap == 151) // Dungeon 
	|| (CurrentMap == 163) // Castle tunnel
	|| (CurrentMap == 164) // Castle Tree
	|| (CurrentMap == 165) // Helm barrel
	|| (CurrentMap == 169) // Japes lobby
	|| (CurrentMap == 170) // Helm lobby
	|| (CurrentMap == 171) // DK's house
	|| (CurrentMap == 173) // Aztec lobby
	|| (CurrentMap == 174) // Galleon lobby
	|| (CurrentMap == 175) // Factory lobby
	|| (CurrentMap == 176) // Training grounds
	|| (CurrentMap == 178) // Fungi lobby
	|| (CurrentMap == 183) // Crypt
	|| (CurrentMap == 193) // Castle lobby
	|| (CurrentMap == 194) // Caves lobby
	|| (CurrentMap == 195) // Snide's room
	|| (CurrentMap == 201) // Helm barrel
	|| (CurrentMap == 202) // Helm barrel
	|| (CurrentMap == 209) // Helm barrel
	|| (CurrentMap == 210) // Helm barrel
	|| (CurrentMap == 211) // Helm barrel
	|| (CurrentMap == 212) // Helm barrel
	) {if((HelmTimerEnabled == 0) && checkFlag(770, TYPE_PERMANENT) == 0) {initHelmTimer();};} 
	else {if(HelmTimerEnabled == 1) {C = HelmCurrentTime; HelmTimerEnabled = 0; S = C - B;};}; 


	// Enables TA & other QoL changes
	tagAnywhere();

	// Start with Simian Slam
	if (MovesBase[0].simian_slam == 0) {for(int i = 0; i < 5; i++) {MovesBase[i].simian_slam = 1;};};

	// Japes lobby opened from start
	setFlag(443, 1, TYPE_PERMANENT);

	// Auto Turn-In Keys	
	if(checkFlag(26, TYPE_PERMANENT) == 1) {setFlag(444, 1, TYPE_PERMANENT);};
	if(checkFlag(74, TYPE_PERMANENT) == 1) {setFlag(445, 1, TYPE_PERMANENT);};
	if(checkFlag(138, TYPE_PERMANENT) == 1) {setFlag(446, 1, TYPE_PERMANENT);};
	if(checkFlag(168, TYPE_PERMANENT) == 1) {setFlag(447, 1, TYPE_PERMANENT);};
	if(checkFlag(236, TYPE_PERMANENT) == 1) {setFlag(448, 1, TYPE_PERMANENT);};
	if(checkFlag(292, TYPE_PERMANENT) == 1) {setFlag(449, 1, TYPE_PERMANENT);};
	if(checkFlag(317, TYPE_PERMANENT) == 1) {setFlag(450, 1, TYPE_PERMANENT);};
	if(checkFlag(380, TYPE_PERMANENT) == 1) {setFlag(451, 1, TYPE_PERMANENT);};

	
	// Removes weather
	actorData* actor_12 = (actorData*)findActorWithType(12);
	*(char*)(actor_12->paad) = 0;	

	// Move "get out" timer to left side of screen
	*(short*)(0x806B7ECA) = 0x10;

	// Change B. Locker Requirements
	*(short*)(0x807446D2) = 10; // Aztec
	*(short*)(0x807446D4) = 30; // Factory
	*(short*)(0x807446D6) = 60; // Galleon
	*(short*)(0x807446D8) = 90; // Fungi
	*(short*)(0x807446DA) = 120; // Caves
	*(short*)(0x807446DC) = 150; // Castle
	*(short*)(0x807446DE) = 180; // Helm

	// Change T&S CB Requirements
	if((MovesBase[0].cb_count[getWorld(CurrentMap,1)] + MovesBase[1].cb_count[getWorld(CurrentMap,1)] + MovesBase[2].cb_count[getWorld(CurrentMap,1)] + MovesBase[3].cb_count[getWorld(CurrentMap,1)] 
	+ MovesBase[4].cb_count[getWorld(CurrentMap,1)]) >= 400) {
	*(short*)(0x807446C0) = 0; // Japes
	*(short*)(0x807446C2) = 0; // Aztec
	*(short*)(0x807446C4) = 0; // Factory
	*(short*)(0x807446C6) = 0; // Galleon
	*(short*)(0x807446C8) = 0; // Fungi
	*(short*)(0x807446CA) = 0; // Caves
	*(short*)(0x807446CC) = 0; // Castle
	} else {
	*(short*)(0x807446C0) = 400; // Japes
	*(short*)(0x807446C2) = 400; // Aztec
	*(short*)(0x807446C4) = 400; // Factory
	*(short*)(0x807446C6) = 400; // Galleon
	*(short*)(0x807446C8) = 400; // Fungi
	*(short*)(0x807446CA) = 400; // Caves
	*(short*)(0x807446CC) = 400; // Castle
	};

	// Increase Arcade price
	*(short*)(0x8064EA6A) = 2;
	*(short*)(0x8064EA92) = -3;


	// float* data = (float*)getMapData(ptr, file, c0, c1);
	// if(file == 0x228) {*data = 20.0f;} return (void*)data;
	
	
	

	// Mad Jack
	if(CurrentMap == 0x9A) {
	*(short*)(0x80033B26) = 0x4220;
	*(short*)(0x800331AA) = 0x4220;
	*(short*)(0x800339EE) = 0x4220;
	*(float*)(0x80036C40) = 3;
	*(float*)(0x80036C44) = 3.2;
	*(float*)(0x80036C48) = 3.4;
	*(float*)(0x80036C4C) = 3.6;
	*(float*)(0x80036C50) = 3.8;};

	for (int i = 0; i < 5; i++) {
// if (MovesBase[i].weapon_bitfield == 1) {MovesBase[i].weapon_bitfield = 2;}; // Skips buying ammo belt
MovesBase[i].instrument_energy = 0; // Instrument energy always zero
};
	
	// Fast Boot	
	*(short*)(0x8071319E) = 0x50;
	*(short*)(0x807131AA) = 5;
	*(short*)(0x8071401E) = 0x50;
	*(short*)(0x8071404E) = 5;

	// Fast warps
	void fastWarp(void* actor, int player_index) {
	unkMultiplayerWarpFunction(actor, player_index);
	renderScreenTransition(6);}
	*(short*)(0x806EE692) = 0x54;
	*(int*)(0x806DC2AC) = 0x0C000000 | (((int)&fastWarp & 0xFFFFFF) >> 2);

	// Fast barrel transformation
	*(short*)(0x8067EAB2) = 1; // OSprint
        *(short*)(0x8067EAC6) = 1; // HC Dogadon 2
        *(short*)(0x8067EACA) = 1; // Others
        *(short*)(0x8067EA92) = 1; // Others 2

	// File startup exit at last checkpoint
	// if(CurrentMap == 80 && checkFlag(775, TYPE_PERMANENT) == 1) {DestMap = 7; DestExit = 10;};
		
	// if((M == 7) && (E == 10) && (checkFlag(775, TYPE_PERMANENT) == 0)) {setFlag(775, 1, TYPE_PERMANENT);};	

	// Galleon water level always high
	// setFlag(160, 1, TYPE_PERMANENT);

};

void earlyFrameFunc(void) {

	// Moves
if((CurrentMap == 1) || (CurrentMap == 5) || (CurrentMap == 25)) {



for (int i = 0; i < 2; i++) {
CrankyMoves[i][0].price = 5;
CrankyMoves[i][1].price = 10;
CrankyMoves[i][2].price = 15;};

for (int i = 0; i < 3; i++) {
CrankyMoves[i+2][0].price = 5;
CrankyMoves[i+2][1].price = 10;};

for (int i = 0; i < 5; i++) {
CandyMoves[i][1].price = 10;

FunkyMoves[i][0].price = 5;
FunkyMoves[i][2].purchase_type = 0xFFFF;
FunkyMoves[i][4].purchase_type = 0xFFFF;
FunkyMoves[i][5].purchase_type = 0xFFFF;
FunkyMoves[i][6].price = 40;
};};
	// Teetering Turtle Troubles
	if(CurrentMap == 18) {
	*(short*)(0x80028022) = 0x4040;};

	// Kremling Kosh
	if(CurrentMap == 0x75) {
	*(short*)(0x80027A02) = 0x32;};

}

                                                                                                                                                                                                                                  