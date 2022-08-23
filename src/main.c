#include "../include/common.h"

static unsigned int S = 0;
static unsigned int C = 0;

void CheckPoint() {S = 600; for (int i = 0; i < 40; i++) {if(checkFlag(469 + i, TYPE_PERMANENT) == 1) {setFlag(509 + i, 1, TYPE_PERMANENT);};}; Save();}

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
	if((CurrentMap == 0x35) && (checkFlag(609, TYPE_PERMANENT) == 1)) {CheckPoint();};
	
	
	// Helm Timer Setup
	int B = 120*(checkFlag(469, TYPE_PERMANENT) + checkFlag(470, TYPE_PERMANENT) + checkFlag(471, TYPE_PERMANENT) + checkFlag(472, TYPE_PERMANENT)
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
	if(CurrentMap == 0x50) {S = 600;};
	HelmStartTime = S + B;
	if((CurrentMap == 0x01) || (CurrentMap == 0x02) || (CurrentMap == 0x05) || (CurrentMap == 0x06) || (CurrentMap == 0x08) 
	|| (CurrentMap == 0x09) || (CurrentMap == 0x0A) || (CurrentMap == 0x0B) || (CurrentMap == 0x0E) || (CurrentMap == 0x0F) 
	|| (CurrentMap == 0x12) || (CurrentMap == 0x19) || (CurrentMap == 0x1B) || (CurrentMap == 0x20) || (CurrentMap == 0x27)
	|| (CurrentMap == 0x33) || (CurrentMap == 0x35) || (CurrentMap == 0x37) || (CurrentMap == 0x3C) || (CurrentMap == 0x41)
	|| (CurrentMap == 0x42) || (CurrentMap == 0x43) || (CurrentMap == 0x44) || (CurrentMap == 0x45) || (CurrentMap == 0x49)
	|| (CurrentMap == 0x4A) || (CurrentMap == 0x4B) || (CurrentMap == 0x4D) || (CurrentMap == 0x4E) || (CurrentMap == 0x4F) 
	|| (CurrentMap == 0x52) || (CurrentMap == 0x53) || (CurrentMap == 0x60) || (CurrentMap == 0x63) || (CurrentMap == 0x65)
	|| (CurrentMap == 0x66) || (CurrentMap == 0x67) || (CurrentMap == 0x68) || (CurrentMap == 0x6A) || (CurrentMap == 0x6F)
	|| (CurrentMap == 0x73) || (CurrentMap == 0x74) || (CurrentMap == 0x75) || (CurrentMap == 0x76) || (CurrentMap == 0x77)
	|| (CurrentMap == 0x78) || (CurrentMap == 0x79) || (CurrentMap == 0x7A) || (CurrentMap == 0x7B) || (CurrentMap == 0x7C) 
	|| (CurrentMap == 0x7D) || (CurrentMap == 0x7E) || (CurrentMap == 0x7F) || (CurrentMap == 0x80) || (CurrentMap == 0x81)
	|| (CurrentMap == 0x82) || (CurrentMap == 0x83) || (CurrentMap == 0x84) || (CurrentMap == 0x85) || (CurrentMap == 0x86)
	|| (CurrentMap == 0x87) || (CurrentMap == 0x88) || (CurrentMap == 0x89) || (CurrentMap == 0x8A) || (CurrentMap == 0x8B)
	|| (CurrentMap == 0x8C) || (CurrentMap == 0x8D) || (CurrentMap == 0x8E) || (CurrentMap == 0x8F) || (CurrentMap == 0x90) 
	|| (CurrentMap == 0x91) || (CurrentMap == 0x92) || (CurrentMap == 0x93) || (CurrentMap == 0x94) || (CurrentMap == 0x95)
	|| (CurrentMap == 0x96) || (CurrentMap == 0x97) || (CurrentMap == 0x9A) || (CurrentMap == 0x9B) || (CurrentMap == 0x9C)
	|| (CurrentMap == 0x9D) || (CurrentMap == 0x9E) || (CurrentMap == 0x9F) || (CurrentMap == 0xA0) || (CurrentMap == 0xA1)
	|| (CurrentMap == 0xA2) || (CurrentMap == 0xB9) || (CurrentMap == 0xC4) || (CurrentMap == 0xC5) || (CurrentMap == 0xC7) 
	|| checkFlag(770, TYPE_PERMANENT) == 1) 
	{if(HelmTimerEnabled == 1) {C = HelmCurrentTime; HelmTimerEnabled = 0; S = C - B;};} else {if(HelmTimerEnabled == 0) {initHelmTimer();};};


	// Enables TA & other QoL changes
	tagAnywhere();

	// Levels 1-7 lobbies open, Helm lobby open with keys 1-7, K. Rool spawned with keys 1-8
	setFlag(443, 1, TYPE_PERMANENT); setFlag(444, 1, TYPE_PERMANENT); setFlag(445, 1, TYPE_PERMANENT); setFlag(447, 1, TYPE_PERMANENT); setFlag(448, 1, TYPE_PERMANENT); 
	
	if(checkFlag(26, TYPE_PERMANENT) == 1 && checkFlag(74, TYPE_PERMANENT) == 1 && checkFlag(138, TYPE_PERMANENT) == 1 && checkFlag(168, TYPE_PERMANENT) == 1 && checkFlag(236, TYPE_PERMANENT) == 1 && checkFlag(292, TYPE_PERMANENT) == 1 && checkFlag(317, TYPE_PERMANENT) == 1) 
	{setFlag(449, 1, TYPE_PERMANENT); setFlag(450, 1,TYPE_PERMANENT);} else {setFlag(450, 0,TYPE_PERMANENT);};
	
	if(checkFlag(26, TYPE_PERMANENT) == 1 && checkFlag(74, TYPE_PERMANENT) == 1 && checkFlag(138, TYPE_PERMANENT) == 1 && checkFlag(168, TYPE_PERMANENT) == 1 && checkFlag(236, TYPE_PERMANENT) == 1 && checkFlag(292, TYPE_PERMANENT) == 1 && checkFlag(317, TYPE_PERMANENT) == 1 && checkFlag(380, TYPE_PERMANENT) == 1) 
	{setFlag(446, 1, TYPE_PERMANENT); setFlag(451, 1,TYPE_PERMANENT);} else {setFlag(451, 0,TYPE_PERMANENT);};

	// Removes weather
	actorData* actor_12 = (actorData*)findActorWithType(12);
	*(char*)(actor_12->paad) = 0;	

	// Move "get out" timer to left side of screen
	*(short*)(0x806B7ECA) = 0x10;

	// Make Mad Jack faster
	if(CurrentMap == 0x9A) {
	*(float*)(0x80036C40) = 5;};
	
}
