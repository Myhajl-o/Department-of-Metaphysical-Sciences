#define _CRT_SECURE_NO_WARNINGS
#include <raylib.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include "name.h"
etap1 Upload1(etap1 a) {
	a.dms = LoadTexture("images/dms.png");
	a.usa = LoadTexture("images/usa.png");
	a.vvid = LoadTexture("images/vvid.png");
	a.exit = LoadTexture("images/exit.png");
	a.con = LoadTexture("images/continue.png");
	a.vvid1 = LoadTexture("images/vvid1.png");
	a.exit1 = LoadTexture("images/exit1.png");
	a.con1 = LoadTexture("images/continue1.png");
	a.exit2 = LoadTexture("images/exit2.png");
	a.con2 = LoadTexture("images/continue2.png");
	a.err = LoadSound("song/incorrect password.mp3");
	a.good = LoadSound("song/correct password.wav");
	a.inter = LoadFont("font/Inter_28pt-Regular.ttf");
	a.v = false;
	a.e = false;
	a.c = false;
	a.c1 = false;
	a.cp1 = false;
	a.pere = false;
	a.pere = 0;
	a.cp = 0;
	a.time = 0;
	a.fps = 0;
	a.rub = 0;
	a.x = 522;
	strcpy_s(a.password,100, "oJ9z1sMa41");
	a.k = 0;
	memset(a.password1, 0, 100);
	return a;
}
etap1 Upload1v(etap1 a) {
	if (a.v) {
		a.pas = GetCharPressed();
		while (a.pas > 0) {
			if ((a.pas >= 32) && (a.pas <= 125) && a.k < 15) {
				a.password1[a.k] = (char)a.pas;
				a.password1[a.k + 1] = '\0';
				a.k++;
			}
			a.pas = GetCharPressed();
		}if (a.vb) {
			a.k--;
			a.x -= 10;
			if (a.k < 0) {
				a.k = 0;
			}
			a.password1[a.k] = '\0';
		}
		a.texts = MeasureTextEx(a.inter, a.password1, 32, 1);
		a.x = a.texts.x + 522;
		a.x += 5;
		if (a.x < 522) {
			a.x = 522;
		}
	}
	else {
		DrawTextEx(a.inter, "Enter password", (Vector2) { 572, 320 }, 32, 2, WHITE);
	}
	if (a.c1) {
		a.c = true;
		a.c1 = false;
	}
	if (a.c) {
		if (strcmp(a.password, a.password1) == 0) {
			a.cp = 2;
			a.c = false;
			PlaySound(a.good);
		}
		else {
			a.cp = 1;
			a.c = false;
			PlaySound(a.err);
		}
	}
	if (a.cp1) {
		if (a.cp == 2) {
			DrawTextEx(a.inter, "Correct password", (Vector2) { 572, 450 }, 32, 2, GREEN);
			if (a.pere == false) {
				a.pere = true;
				a.peret = 120;
			}
		}
		else if (a.cp == 1) {
			DrawTextEx(a.inter, "Incorrect password", (Vector2) { 572, 450 }, 32, 2, RED);
		}
	}
	return a;
}
etap2 LoadGif(const char* filename) {
	etap2 b = { 0 };
	b.file = 0;
	b.gif = LoadImageAnim(filename, &b.file);
	b.giph = LoadTextureFromImage(b.gif);
	b.codmw2 = LoadSound("song/codmw2.wav");
	b.totalf = b.file;
	b.f = 0;
	b.flast = 10;
	b.fps = 0;
	return b;
}

etap2 UpdateGif(etap2 b) {
	b.fps++;
	if (b.fps >= b.flast) {
		b.fps = 0;
		if (b.f < b.totalf-1) {
			b.f++;
		}
		unsigned int offset = b.gif.width * b.gif.height * 4 * b.f;
		UpdateTexture(b.giph, ((unsigned char*)b.gif.data) + offset);
	}
	return b;
}
void DrawGif(etap2 b) {
	DrawTexture(b.giph, 363, 204, WHITE);
}
etap3 Upload3(etap3 c) {
	c.fon = LoadTexture("images/fon3.png");
	c.dms = LoadTexture("images/dmsWHITE.png");
	c.textfield = LoadTexture("images/text field.png");
	c.accept = LoadTexture("images/accept.png");
	c.accept1 = LoadTexture("images/accept1.png");
	c.accept2 = LoadTexture("images/accept2.png");
	c.accept3 = LoadTexture("images/accept3.png");
	c.next = LoadTexture("images/next.png");
	c.next1 = LoadTexture("images/next1.png");
	c.next2 = LoadTexture("images/next2.png");
	c.cencel = LoadTexture("images/cencel.png");
	c.cencel1 = LoadTexture("images/cencel1.png");
	c.cencel2 = LoadTexture("images/cencel2.png");
	c.loadText=LoadFileText("text/policy.dms");
	c.policy = TextReplace(c.loadText, "\n", "\n\n");
	c.mono = LoadFont("font/SplineSansMono-Regular.ttf");
	UnloadFileText(c.loadText);
	c.tlenght = TextLength(c.policy);
	c.theght = MeasureTextEx(c.mono, c.tempt, 20, 2).y;
	c.scrol = LoadTexture("images/scroll3.png");
	c.autext = LoadMusicStream("song/audiotext.wav");
	c.audiob = LoadTexture("images/dynamik.png");
	c.audiob1 = LoadTexture("images/dynamik1.png");
	c.povzunok = LoadTexture("images/povzunok.png");
	c.povzunok1 = LoadTexture("images/povzunok1.png");
	PlayMusicStream(c.autext);
	c.visiblechar = 0;
	c.timer = 0;
	c.linecount = 0;
	c.dragging = false;
	c.galochka = false;
	c.nextb = false;
	c.cencelb = false;
	c.rub = false;
	c.timern = 0;
	c.timerc = 0;
	c.onoff = true;
	c.tick = 0;
	c.x = 0;
	c.fps = 0;
	return c;
}
etap3 Drawtext(etap3 c) {
	if (c.linecount == 0) {
		c.linecount = 1;
		c.currentlinew = 0;
		for (c.i = 0; c.i < c.tlenght; c.i++) {
			c.tempt[0] = c.policy[c.i];
			c.tempt[1] = '\0';
			c.currentlinew += MeasureTextEx(c.mono, c.tempt, 20, 2).x;
			if (c.policy[c.i] == ' ') {
				c.lastspase = c.i;
			}
			if (c.policy[c.i] == '\n') {
				c.currentlinew = 0;
				c.linecount++;
			}if (c.currentlinew > 621) {
					c.policy[c.lastspase] = '\n';
					c.currentlinew = 0;
					c.linecount++;
			}
		}
	}
		if (c.visiblechar < c.tlenght) {
			c.timer++;
			if (c.timer > 1) {
				c.visiblechar += 5;
				c.timer = 0;
			}
		}
	c.fullHeight = c.linecount * (20 + 2) + 100;
	if (!c.dragging&&CheckCollisionPointRec(c.virtualMouse, (Rectangle) { 545, 101, 622, 407 })) {
		c.scrolly += GetMouseWheelMove() * 20.0f;
	}
	if (c.scrolly > 0) {
		c.scrolly = 0;
	}
	c.maxScroll = -(c.fullHeight-407);
	if (c.scrolly < c.maxScroll) {
		c.scrolly = c.maxScroll;
	}
	c.progress = c.scrolly / c.maxScroll;
	if (c.progress < 0) {
		c.progress = 0;
	}if (c.progress > 1) {
		c.progress = 1;
	}
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		if (CheckCollisionPointRec(c.virtualMouse, (Rectangle) { 1190, c.scrollBarY, 30, 20 })) {
			c.dragging = true;
			c.draggingofset = c.virtualMouse.y - c.scrollBarY;
		}
	}
	if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
		c.dragging = false;
	}
	if (c.dragging) {
		c.newSliderY = c.virtualMouse.y - c.draggingofset;
		if (c.newSliderY < 115) {
			c.newSliderY = 115;
		}if (c.newSliderY > 508) {
			c.newSliderY = 508;
		}
		c.ratio = (c.newSliderY - 115) / 373.0f;
		c.scrolly = c.ratio * c.maxScroll;
	}
	c.scrollBarY = 115 + (c.progress * 373);
	DrawTexture(c.scrol, 1190, (int)c.scrollBarY, WHITE);
	BeginScissorMode(545, 101, 622, 407);
	c.backupChar = c.policy[c.visiblechar];
	c.policy[c.visiblechar] = '\0';
	DrawTextEx(c.mono, c.policy, (Vector2){545,101+c.scrolly}, 20, 2, BLACK);
	c.policy[c.visiblechar] = c.backupChar;
	EndScissorMode();
	return c;
}
etap4 Upload4(etap4 d) {
	d.fon = LoadTexture("images/fon4.png");
	d.dms = LoadTexture("images/dms4.png");
	d.field = LoadTexture("images/field4.png");
	d.scroll = LoadTexture("images/scroll4.png");
	d.bscroll = LoadTexture("images/bscroll4.png");
	d.file1 = LoadTexture("images/file1.png");
	d.infofile1 = LoadTexture("images/infofile1.png");
	d.file11 = LoadTexture("images/file11.png");
	d.file12 = LoadTexture("images/file12.png");
	d.file2 = LoadTexture("images/file2.png");
	d.infofile2 = LoadTexture("images/infofile2.png");
	d.file21 = LoadTexture("images/file21.png");
	d.file22 = LoadTexture("images/file22.png");
	d.folders[0].file = LoadTexture("images/file3.png");
	d.folders[0].file1 = LoadTexture("images/file31.png");
	d.folders[0].file2 = LoadTexture("images/file32.png");
	d.folders[1].file = LoadTexture("images/file4.png");
	d.folders[1].file1 = LoadTexture("images/file41.png");
	d.folders[1].file2 = LoadTexture("images/file42.png");
	d.folders[2].file = LoadTexture("images/file5.png");
	d.folders[2].file1 = LoadTexture("images/file51.png");
	d.folders[2].file2 = LoadTexture("images/file52.png");
	d.folders[3].file = LoadTexture("images/file6.png");
	d.folders[3].file1 = LoadTexture("images/file61.png");
	d.folders[3].file2 = LoadTexture("images/file62.png");
	d.folders[4].file = LoadTexture("images/file7.png");
	d.folders[4].file1 = LoadTexture("images/file71.png");
	d.folders[4].file2 = LoadTexture("images/file72.png");
	d.folders[0].basedY = 516;
	d.folders[1].basedY = 614;
	d.folders[2].basedY = 712;
	d.folders[3].basedY = 810;
	d.folders[4].basedY = 908;
	d.close = LoadTexture("images/close.png");
	d.close1 = LoadTexture("images/close1.png");
	d.close2 = LoadTexture("images/close2.png");
	d.timef1 = 0;
	d.timef2 = 0;
	d.folders[0].time=0;
	d.folders[1].time=0;
	d.folders[2].time=0;
	d.folders[3].time=0;
	d.folders[4].time=0;
	d.timec = 0;
	d.inf1=false;
	d.inf2 = false;
	d.f1 = false;
	d.f2 = false;
	d.folders[0].f = false;
	d.folders[1].f = false;
	d.folders[2].f = false;
	d.folders[3].f = false;
	d.folders[4].f = false;
	return d;
}
void Draw4(etap4 d) {
	DrawTexture(d.fon, 0, 0, WHITE);
	DrawTexture(d.dms, 0, 14, WHITE);
	DrawTexture(d.field, 18,288, WHITE);
	DrawTexture(d.scroll, 1300, 309, WHITE);
	if (d.inf1) {
		DrawTexture(d.infofile1, 341, 31, WHITE);
	}
	if (d.inf2) {
		DrawTexture(d.infofile2, 341, 31, WHITE);
	}
}
etap4 UpdateScrollLogic(etap4 d) {
	d.wheel= GetMouseWheelMove();
	if (d.scrollOffset < 0) {
		d.scrollOffset = 0;
	}
	d.maxScroll = 500.0f;
	if (d.scrollOffset > d.maxScroll) {
		d.scrollOffset = d.maxScroll;
	}
	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
		if (CheckCollisionPointRec(d.virtualMouse, (Rectangle) { 1300, d.scrollY, 25, 58 })) {
			d.dragging = true;
			d.draggingofset = d.virtualMouse.y - d.scrollY;
		}
	}
	else {
		d.dragging = false;
	}
	
	if (d.dragging) {
		d.scrollY = d.virtualMouse.y - d.draggingofset;
		if (d.scrollY < 334) {
			d.scrollY = 334;
		}if (d.scrollY > 629) {
			d.scrollY = 629;
		}

		d.ratio = (d.scrollY - 334) / 295.0f;
		d.scrollOffset = d.ratio * d.maxScroll;
	}
	else {
		if (d.wheel != 0) {
			d.scrollOffset -= d.wheel * 30.0f;
		}
		if (d.scrollOffset < 0) d.scrollOffset = 0;
		if (d.scrollOffset > d.maxScroll) d.scrollOffset = d.maxScroll;
		d.ratio = d.scrollOffset / d.maxScroll;
		d.scrollY = 334 + (d.ratio * 295.0f);
	}
	return d;
}
int DrawFolderButton(FolderButton* btn, float scrollOffset, Vector2 virtualMouse) {
	float screenY = btn->basedY - scrollOffset;
	int targetEtap = 4;
	if (btn->time > 0) {
		DrawTexture(btn->file2, 90, screenY+2, WHITE);
		btn->time--;
		if (btn->time == 0) {
			btn->f = true;
			targetEtap = 5;
		}
	}
	else {
		if (CheckCollisionPointRec(virtualMouse, (Rectangle) { 86, screenY, 1147, 64 })) {
			if (CheckCollisionPointRec(virtualMouse, (Rectangle) { 28, 299, 1310, 425 })) {
				DrawTexture(btn->file1, 56,screenY-30,WHITE);
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					btn->time = 5;
				}
			}
		}
		else {
			DrawTexture(btn->file, 86, screenY, WHITE);
		}
	}
	return targetEtap;
}
etap5 Upload5(etap5 e) {
	e.fon = LoadTexture("images/fon5.png");
	e.novebar = LoadTexture("images/nov.png");
	e.novedit = LoadTexture("images/novedit.png");
	e.scroll = LoadTexture("images/scroll5.png");
	e.bscroll = LoadTexture("images/bscroll4.png");
	e.close = LoadTexture("images/close.png");
	e.close1 = LoadTexture("images/close1.png");
	e.close2 = LoadTexture("images/close2.png");
	e.timec = 0;
	e.back = LoadTexture("images/back.png");
	e.back1 = LoadTexture("images/back1.png");
	e.back2 = LoadTexture("images/back2.png");
	e.editb = LoadTexture("images/edit.png");
	e.editb1 = LoadTexture("images/edit1.png");
	e.textf1 = LoadTexture("images/textf1.png");
	e.textf2 = LoadTexture("images/textf2.png");
	e.textf3 = LoadTexture("images/textf3.png");
	e.textf4 = LoadTexture("images/textf4.png");
	e.textf5 = LoadTexture("images/textf5.png");
	e.textf6 = LoadTexture("images/textf6.png");
	e.textf7 = LoadTexture("images/textf7.png");
	e.winp = LoadTexture("images/winp.png");
	e.continueb = LoadTexture("images/continuee.png");
	e.continueb1 = LoadTexture("images/continuee1.png");
	e.exit = LoadTexture("images/exite.png");
	e.exit1 = LoadTexture("images/exite1.png");
	e.saveb = LoadTexture("images/save.png");
	e.saveb1 = LoadTexture("images/save1.png");
	e.saveb2 = LoadTexture("images/save2.png");
	e.saveb3 = LoadTexture("images/save3.png");
	e.cypherrr = LoadTexture("images/cypher.png");
	e.cypher = LoadTexture("images/cypher1.png");
	e.cypher1 = LoadTexture("images/cypher2.png");
	e.cypher2 = LoadTexture("images/cypher3.png");
	e.cypher3 = LoadTexture("images/cypher4.png");
	e.cypher4 = LoadTexture("images/cypher5.png");
	e.cypher2act = LoadTexture("images/cypher3act.png");
	e.cypher3act = LoadTexture("images/cypher4act.png");
	e.cypher4act = LoadTexture("images/cypher5act.png");
	e.savewindow = LoadTexture("images/savewindow.png");
	e.cencel5b = LoadTexture("images/cencel5.png");
	e.cencel5b1 = LoadTexture("images/cencel51.png");
	e.ok5b = LoadTexture("images/ok5.png");
	e.ok5b1 = LoadTexture("images/ok51.png");
	e.enigmawin = LoadTexture("images/enigmawin.png");
	e.frame = LoadTexture("images/frame.png");
	e.xorwin = LoadTexture("images/xorwin.png");
	e.timeb = 0;
	e.isFileLoaded = false;
	int codepoints[512] = { 0 };
	for (int i = 0; i < 95; i++) codepoints[i] = 32 + i;
	for (int i = 0; i < 255; i++) codepoints[95 + i] = 0x0400 + i;
	e.inter = LoadFontEx("font/Inter_28pt-Regular.ttf", 28, codepoints, 350);
	e.linecout = 0;
	e.edit = false;
	e.bs = false;
	e.enter = false;
	e.cursor = false;
	e.wp = false;
	strcpy_s(e.password1, 20, "0Yq3Bt7ge8");
	memset(e.password, 0, 20);
	e.ok = false;
	e.correct = false;
	e.i1 = 0;
	e.times = 0;
	e.save = false;
	e.cyp = false;
	e.bufferSize = 102400;
	e.textBuffer = (char*)calloc(e.bufferSize, sizeof(char));
	strcpy_s(e.cypherName0, 30, "Ceasar");
	strcpy_s(e.cypherName1, 30, "-Ceasar");
	strcpy_s(e.cypherName2, 30, "castomCeasar#_#_");
	strcpy_s(e.cypherName3, 30, "Enigma");
	strcpy_s(e.cypherName4, 30, "XOR");
	strcpy_s(e.cypherName5, 30, "Trithemius");
	strcpy_s(e.cypherName6, 30, "-Trithemius");
	e.cypherName[0] = e.cypherName0;
	e.cypherName[1] = e.cypherName1;
	e.cypherName[2] = e.cypherName2;
	e.cypherName[3] = e.cypherName3;
	e.cypherName[4] = e.cypherName4;
	e.cypherName[5] = e.cypherName5;
	e.cypherName[6] = e.cypherName6;
	memset(e.cypherActive, false, 10);
	e.savewin = false;
	int temp_upper[] = { 1040, 1041, 1042, 1043, 1168, 1044, 1045, 1028, 1046, 1047, 1048, 1030, 1031, 1049, 1050, 1051, 1052, 1053, 1054, 1055, 1056, 1057, 1058, 1059, 1060, 1061, 1062, 1063, 1064, 1065, 1068, 1070, 1071 };
	int temp_lower[] = { 1072, 1073, 1074, 1075, 1169, 1076, 1077, 1108, 1078, 1079, 1080, 1110, 1111, 1081, 1082, 1083, 1084, 1085, 1086, 1087, 1088, 1089, 1090, 1091, 1092, 1093, 1094, 1095, 1096, 1097, 1100, 1102, 1103 };

	memcpy(e.ukr_upper, temp_upper, sizeof(temp_upper));
	memcpy(e.ukr_lower, temp_lower, sizeof(temp_lower));
	e.enigmaswtch=false;
	memset(e.ennumber, false, 3);
	memset(e.enok, false, 3);
	memset(e.starten, false, 3);
	e.xorSwitch;
	memset(e.keyBuffer,'\0',30);
	e.keyi=0;
	e.xorok = false;
	e.savetime = 0;
	e.fps = 0;
	e.backText = (char*)calloc(e.bufferSize, sizeof(char));
	e.canUndo = false;
	e.backText1 = (char*)calloc(e.bufferSize, sizeof(char));
	e.backText2 = (char*)calloc(e.bufferSize, sizeof(char));
	e.canUndo1 = false;
	e.canUndo2 = false;
	return e;
}
void Draw5(etap5 e) {
	DrawTexture(e.fon, 0, 0, WHITE);
	DrawTexture(e.novebar, 0, 0, WHITE);
	DrawTexture(e.scroll, 1325, 180, WHITE);
	DrawTexture(e.cypherrr, 127, 22, WHITE);
	if (e.files[0]) {
		DrawTexture(e.textf1, 391, 25, WHITE);
	}
	else if (e.files[1]) {
		DrawTexture(e.textf2, 363, 25, WHITE);
	}
	else if (e.files[2]) {
		DrawTexture(e.textf3, 562, 25, WHITE);
	}
	else if (e.files[3]) {
		DrawTexture(e.textf4, 562, 25, WHITE);
	}
	else if (e.files[4]) {
		DrawTexture(e.textf5, 562, 25, WHITE);
	}
	else if (e.files[5]) {
		DrawTexture(e.textf6, 562, 25, WHITE);
	}
	else if (e.files[6]) {
		DrawTexture(e.textf7, 562, 25, WHITE);
	}
}
etap5 Scrollogic(etap5 e) {
	e.wheel = GetMouseWheelMove();
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		if (CheckCollisionPointRec(e.virtualMouse, (Rectangle) { 1325, e.scrollY, 25, 58 })) {
			e.dragging = true;
			e.draggingofset = e.virtualMouse.y - e.scrollY;
		}
	}
	if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
		e.dragging = false;
	}
	if (e.dragging) {
		e.scrollY = e.virtualMouse.y - e.draggingofset;
		if (e.scrollY < 207) {
			e.scrollY = 207;
		}if (e.scrollY > 669) {
			e.scrollY = 669;
		}

		e.ratio = (e.scrollY - 207) / 462.0f;
		e.scrolloffset = e.ratio * e.maxScroll;
	}
	else {
		if (e.wheel != 0) {
			e.scrolloffset -= e.wheel * 40.0f;
		}
		if (e.scrolloffset < 0) e.scrolloffset = 0;
		if (e.scrolloffset > e.maxScroll) e.scrolloffset = e.maxScroll;
		e.ratio = e.scrolloffset / e.maxScroll;
		e.scrollY = 207 + (e.ratio * 462.0f);
	}
	return e;
}
etap5 textfile(etap5 e) {
	memset(e.textBuffer, 0, e.bufferSize);
	char* tempText = NULL;
	if (e.files[0]) {
		tempText = LoadFileText("text/file1.dms");
	}
	else if (e.files[1]) {
		tempText = LoadFileText("text/file2.dms");
	}
	else if (e.files[2]) {
		tempText = LoadFileText("text/file3.dms");
	}
	else if (e.files[3]) {
		tempText = LoadFileText("text/file4.dms");
	}
	else if (e.files[4]) {
		tempText = LoadFileText("text/file5.dms");
	}
	else if (e.files[5]) {
		tempText = LoadFileText("text/file6.dms");
	}
	else if (e.files[6]) {
		tempText = LoadFileText("text/file7.dms");
	}
	if (tempText != NULL) {
		if (strlen(tempText) < e.bufferSize) {
			strcpy_s(e.textBuffer, e.bufferSize, tempText);
		}
		else {
			strncpy_s(e.textBuffer, e.bufferSize, tempText, e.bufferSize - 1);
		}
		UnloadFileText(tempText);
	}
	else {
		strcpy(e.textBuffer, "[SYSTEM ERROR]: File not found or corrupted.");
	}
	if (e.isFileLoaded==false) {
		e.linecout = 1;
		e.currentline = 0.0f;
		e.lastspase = -1;
		e.textl = strlen(e.textBuffer);
		for (e.i = 0; e.i < e.textl; e.i++) {
			e.tempt[0] = e.textBuffer[e.i];
			e.tempt[1] = '\0';
			e.currentline += MeasureTextEx(e.inter, e.tempt, 26, 2.0f).x+2.0f;

			if (e.textBuffer[e.i] == ' ') {
				e.lastspase = e.i;
			}
			else if (e.textBuffer[e.i] == '\n') {
				e.currentline = 0.0f;
				e.linecout++;
				e.lastspase = -1;
			}
			if (e.currentline > 1260.0f) {
				if (e.lastspase != -1) {
					e.textBuffer[e.lastspase] = '\n';
					e.i = e.lastspase;
					e.currentline = 0.0f;
					e.linecout++;
					e.lastspase = -1;
				}
				else {
					e.currentline = 0.0f;
					e.linecout++;
				}
			}
		}
	}
	e.isFileLoaded = true;
	return e;
}
etap5 editmode(etap5 e) {

	e.len = strlen(e.textBuffer);
	bool ctrl = IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL);
	if (ctrl && IsKeyPressed(KEY_C)) {
		SetClipboardText(e.textBuffer);
	}
	if (ctrl && IsKeyPressed(KEY_V)) {
		const char* clipText = GetClipboardText();

		if (clipText != NULL) {
			SaveUndoState(&e);
			int clipLen = strlen(clipText);
			if (e.len + clipLen < 102300) {
				memmove(&e.textBuffer[e.k + clipLen], &e.textBuffer[e.k], e.len - e.k + 1);
				memcpy(&e.textBuffer[e.k], clipText, clipLen);
				e.k += clipLen;
				e.len += clipLen;
			}
		}
	}
	if (ctrl && IsKeyPressed(KEY_Z)&&e.canUndo) {
		strcpy_s(e.textBuffer, e.bufferSize, e.backText);
		e.len = strlen(e.textBuffer);
		if (e.k > e.len) e.k = e.len;
		strcpy_s(e.backText, e.bufferSize, e.backText1);
		e.canUndo = e.canUndo1;

		strcpy_s(e.backText1, e.bufferSize, e.backText2);
		e.canUndo1 = e.canUndo2;
		e.canUndo2 = false;
	}
	if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
		SaveUndoState(&e);
	}

	if (e.left && e.k > 0) {
		e.k--;
		while (e.k > 0 && (e.textBuffer[e.k] & 0xC0) == 0x80) e.k--;
	}
	if (e.right && e.k < e.len) {
		e.k++;
		while (e.k < e.len && (e.textBuffer[e.k] & 0xC0) == 0x80) e.k++;
	}

	if (e.up) {
		e.currStart = e.k;
		while (e.currStart > 0 && e.textBuffer[e.currStart - 1] != '\n') e.currStart--;

		if (e.currStart > 0) {
			e.offset = e.k - e.currStart;
			e.prevEnd = e.currStart - 1;
			e.prevStart = e.prevEnd;
			while (e.prevStart > 0 && e.textBuffer[e.prevStart - 1] != '\n') e.prevStart--;

			e.prevLen = e.prevEnd - e.prevStart;
			if (e.offset > e.prevLen) e.k = e.prevEnd;
			else e.k = e.prevStart + e.offset;
		}
	}

	if (e.down) {
		e.currStart = e.k;
		while (e.currStart > 0 && e.textBuffer[e.currStart - 1] != '\n') e.currStart--;
		e.offset = e.k - e.currStart;

		e.nextStart = e.k;
		while (e.nextStart < e.len && e.textBuffer[e.nextStart] != '\n') e.nextStart++;

		if (e.nextStart < e.len) {
			e.nextStart++;
			e.nextEnd = e.nextStart;
			while (e.nextEnd < e.len && e.textBuffer[e.nextEnd] != '\n') e.nextEnd++;

			e.nextLen = e.nextEnd - e.nextStart;
			if (e.offset > e.nextLen) e.k = e.nextEnd;
			else e.k = e.nextStart + e.offset;
		}
	}

	e.letter = GetCharPressed();
	while (e.letter > 0) {
		if (e.letter >= 32 && e.len < 102300) {
			e.utf8char = CodepointToUTF8(e.letter, &e.byteSize);

			if (e.x > 1250) {
				memmove(&e.textBuffer[e.k + 1], &e.textBuffer[e.k], e.len - e.k + 1);
				e.textBuffer[e.k] = '\n';
				e.k++; e.len++;
			}

			memmove(&e.textBuffer[e.k + e.byteSize], &e.textBuffer[e.k], e.len - e.k + 1);
			for (e.i = 0; e.i < e.byteSize; e.i++) {
				e.textBuffer[e.k + e.i] = e.utf8char[e.i];
			}
			e.k += e.byteSize;
			e.len += e.byteSize;
		}
		e.letter = GetCharPressed();
	}

	if (e.bs && e.k > 0) {
		e.delSize = 1;
		while (e.k - e.delSize > 0 && (e.textBuffer[e.k - e.delSize] & 0xC0) == 0x80) {
			e.delSize++;
		}
		memmove(&e.textBuffer[e.k - e.delSize], &e.textBuffer[e.k], e.len - e.k + 1);
		e.k -= e.delSize;
		e.len -= e.delSize;
	}

	if (e.enter && e.len < 102300) {
		memmove(&e.textBuffer[e.k + 1], &e.textBuffer[e.k], e.len - e.k + 1);
		e.textBuffer[e.k] = '\n';
		e.k++; e.len++;
	}

	e.linecout = 1;
	e.currentLineStart = 0;

	for (e.i = 0; e.i < e.k; e.i++) {
		if (e.textBuffer[e.i] == '\n') {
			e.linecout++;
			e.currentLineStart = e.i + 1;
		}
	}

	memset(e.tempLine, 0, sizeof(e.tempLine));
	e.segLen = e.k - e.currentLineStart;

	if (e.segLen > 0 && e.segLen < 1024) {
		strncpy(e.tempLine, &e.textBuffer[e.currentLineStart], e.segLen);
		e.tempLine[e.segLen] = '\0';
		e.x = 32 + MeasureTextEx(e.inter, e.tempLine, 26, 2.0f).x;
	}
	else {
		e.x = 32;
	}

	return e;
}
etap5 editpassword(etap5 e) {
	e.fps++;
	e.lettp = GetCharPressed();
	while (e.lettp > 0) {
		if (e.lettp >= 32 && e.lettp <= 126 && e.i1 < 10) {
			e.password[e.i1] = (char)e.lettp;
			e.i1++;
			e.password[e.i1] = '\0';
		}
		e.lettp = GetCharPressed();
	}
	if ((IsKeyPressed(KEY_BACKSPACE) || IsKeyPressedRepeat(KEY_BACKSPACE)) && e.i1 > 0) {
		e.i1--;
		e.password[e.i1] = '\0';
	}
	if (((e.fps / 20) % 3 == 0) || ((e.fps / 20) == 1)) {
		float x;
		float tlenght = MeasureTextEx(e.inter, e.password, 24, 2.0f).x;
		x = 178 + tlenght;
		DrawRectangle(x, 660, 12, 3, BLACK);
	}
	if (e.correct) {
		DrawTexture(e.continueb, 135, 717, WHITE);
		if (strcmp(e.password, e.password1) == 0) {
			e.correct = false;
			e.wp = false;
			e.edit = true;
			e.save = true;
		}
		else {
			e.correct = false;
			memset(e.password, 0, 20);
			e.i1 = 0;
		}
	}
	else {
		if (CheckCollisionPointRec(e.virtualMouse, (Rectangle) { 135, 717, 100, 32 })) {
			DrawTexture(e.continueb1, 135, 717, WHITE);
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				e.correct = true;
			}
		}
		else {
			DrawTexture(e.continueb, 135, 717, WHITE);
		}
	}
	if (CheckCollisionPointRec(e.virtualMouse, (Rectangle) { 344, 717, 100, 32 })) {
		DrawTexture(e.exit1, 344, 717, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			memset(e.password, 0, 20);
			e.wp = false;
		}
	}
	else {
		DrawTexture(e.exit, 344, 717, WHITE);
	}
	return e;
}
void Savefile(etap5 e) {
	if (e.files[0]) {
		SaveFileText("text/file1.dms", e.textBuffer);
	}
	else if (e.files[1]) {
		SaveFileText("text/file2.dms", e.textBuffer);
	}
	else if (e.files[2]) {
		SaveFileText("text/file3.dms", e.textBuffer);
	}
	else if (e.files[3]) {
		SaveFileText("text/file4.dms", e.textBuffer);
	}
	else if (e.files[4]) {
		SaveFileText("text/file5.dms", e.textBuffer);
	}
	else if (e.files[5]) {
		SaveFileText("text/file6.dms", e.textBuffer);
	}
	else if (e.files[6]) {
		SaveFileText("text/file7.dms", e.textBuffer);
	}
}
etap5 Cypherbutton(etap5 e) {
	DrawTexture(e.cypher1, 319, 72, WHITE);
	if (CheckCollisionPointRec(e.virtualMouse, (Rectangle) { 127, 91, 217, 30 })) {
		DrawTexture(e.cypher2act, 127, 91, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			memset(e.cypherActive, false, 10);
			e.cypherActive[0] = true;
			e.cyp = false;
		}
	}
	else {
		DrawTexture(e.cypher2, 127, 91, WHITE);
	}
	if (CheckCollisionPointRec(e.virtualMouse, (Rectangle) { 127, 123, 217, 30 })) {
		DrawTexture(e.cypher3act, 127, 123, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			memset(e.cypherActive, false, 10);
			e.cypherActive[1] = true;
			e.cyp = false;
		}
	}
	else {
		DrawTexture(e.cypher3, 127, 123, WHITE);
	}
	if (CheckCollisionPointRec(e.virtualMouse, (Rectangle) { 127, 153, 217, 30 })) {
		DrawTexture(e.cypher3act, 127, 153, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			memset(e.cypherActive, false, 10);
			e.cypherActive[2] = true;
			e.cyp = false;
		}
	}
	else {
		DrawTexture(e.cypher3, 127, 153, WHITE);
	}
	if (CheckCollisionPointRec(e.virtualMouse, (Rectangle) { 127, 183, 217, 30 })) {
		DrawTexture(e.cypher3act, 127, 183, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			memset(e.cypherActive, false, 10);
			memset(e.starten, false, 3);
			memset(e.numBuffer0, '\0', 10);
			memset(e.numBuffer1, '\0', 10);
			memset(e.numBuffer2, '\0', 10);
			e.cypherActive[3] = true;
			e.enigmaswtch = true;
			e.i_num0 = 0;
			e.i_num1 = 0;
			e.i_num2 = 0;
			e.cyp = false;
		}
	}
	else {
		DrawTexture(e.cypher3, 127, 183, WHITE);
	}
	if (CheckCollisionPointRec(e.virtualMouse, (Rectangle) { 127, 213, 217, 30 })) {
		DrawTexture(e.cypher3act, 127, 213, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			memset(e.cypherActive, false, 10);
			e.cypherActive[4] = true;
			e.xorSwitch = true;
			memset(e.keyBuffer, '\0', 30);
			e.keyi = 0;
			e.xorok = false;
			e.cyp = false;
		}
	}
	else {
		DrawTexture(e.cypher3, 127, 213, WHITE);
	}
	if (CheckCollisionPointRec(e.virtualMouse, (Rectangle) { 127, 243, 217, 30 })) {
		DrawTexture(e.cypher3act, 127, 243, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			memset(e.cypherActive, false, 10);
			e.cypherActive[5] = true;
			e.cyp = false;
		}
	}
	else {
		DrawTexture(e.cypher3, 127, 243, WHITE);
	}
	if (CheckCollisionPointRec(e.virtualMouse, (Rectangle) { 127, 273, 217, 30 })) {
		DrawTexture(e.cypher4act, 127, 273, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			memset(e.cypherActive, false, 10);
			e.cypherActive[6] = true;
			e.cyp = false;
		}
	}
	else {
		DrawTexture(e.cypher4, 127, 273, WHITE);
	}
	DrawTextEx(e.inter, e.cypherName[0], (Vector2) { 132, 100 }, 20, 2.0f, BLACK);
	DrawTextEx(e.inter, e.cypherName[1], (Vector2) { 132, 130 }, 20, 2.0f, BLACK);
	DrawTextEx(e.inter, e.cypherName[2], (Vector2) { 132, 160 }, 20, 2.0f, BLACK);
	DrawTextEx(e.inter, e.cypherName[3], (Vector2) { 132, 190 }, 20, 2.0f, BLACK);
	DrawTextEx(e.inter, e.cypherName[4], (Vector2) { 132, 220 }, 20, 2.0f, BLACK);
	DrawTextEx(e.inter, e.cypherName[5], (Vector2) { 132, 250 }, 20, 2.0f, BLACK);
	DrawTextEx(e.inter, e.cypherName[6], (Vector2) { 132, 280 }, 20, 2.0f, BLACK);
	return e;
}
void cypheractived(etap5 e) {
	for (int i = 0; i < 7; i++) {
		if (e.cypherActive[i]) {
			DrawTextEx(e.inter, e.cypherName[i], (Vector2) { 132, 70 }, 20, 2.0f, BLACK);
		}
	}
}
etap5 SaveWindow(etap5 e) {
	DrawTexture(e.savewindow, 460, 288, WHITE);
	for (int i = 0; i < 7; i++) {
		if (e.cypherActive[i]) {
			DrawTextEx(e.inter, e.cypherName[i], (Vector2) { 703, 381 }, 20, 2.0f, BLACK);
		}
	}
	if (CheckCollisionPointRec(e.virtualMouse, (Rectangle) { 646, 449, 100, 32 })) {
		DrawTexture(e.cencel5b1, 646, 449, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			SaveUndoState(&e);
			Savefile(e);
			e.savetime = 120;
			e.savewin = false;
		}
	}
	else {
		DrawTexture(e.cencel5b, 646, 449, WHITE);
	}

	if (CheckCollisionPointRec(e.virtualMouse, (Rectangle) { 790, 449, 100, 32 })) {
		DrawTexture(e.ok5b1, 790, 449, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			SaveUndoState(&e);
			CypherText(e);
			Savefile(e);
			e.savetime = 120;
			e.savewin = false;
		}
	}
	else {
		DrawTexture(e.ok5b, 790, 449, WHITE);
	}
	return e;
}
void CypherText(etap5 e) {
	if (e.cypherActive[0]) {
		e = Ceasar(e, 1, false);
	}
	else if (e.cypherActive[1]) {
		e = Ceasar(e, - 1, false);
	}
	else if (e.cypherActive[2]) {
		e = Ceasar(e, 1, true);
	}
	else if (e.cypherActive[3]) {
		e = Enigma(e);
	}
	else if (e.cypherActive[4]) {
		e = XOR(e);
	}
	else if (e.cypherActive[5]) {
		e = Trithemius(e, false);
	}
	else if (e.cypherActive[6]) {
		e = Trithemius(e, true);
	}
}
etap5 Ceasar(etap5 e , int x, bool jump) {
	int len = strlen(e.textBuffer);
	if (len == 0) {
		return e;
	}
	char* tempBuffer = (char*)calloc(len + 10, sizeof(char));
	int tempIndex = 0;
	int i = 0;
	bool shift = true;
	while (i < len) {
		int bytesProcessed = 0;
		int cp = GetCodepoint(&e.textBuffer[i], &bytesProcessed);
		int newCp = cp;
		if (shift) {
			if (cp >= 'A' && cp <= 'Z') {
				newCp = 'A' + (cp - 'A' + x % 26 + 26) % 26;
			}
			else if (cp >= 'a' && cp <= 'z') {
				newCp = 'a' + (cp - 'a' + x % 26 + 26) % 26;
			}
			else {
				bool found = false;
				for (int j = 0; j < 33; j++) {
					if (cp == e.ukr_upper[j]) {
						newCp = e.ukr_upper[(j + x % 33 + 33) % 33];
						found = true;
						break;
					}
				}if (!found) {
					for (int j = 0; j < 33; j++) {
						if (cp == e.ukr_lower[j]) {
							newCp = e.ukr_lower[(j + x % 33 + 33) % 33];
							break;
						}
					}
				}
			}
		}
		int utf8Size = 0;
		const char* utf8 = CodepointToUTF8(newCp, &utf8Size);
		for (int k = 0; k < utf8Size; k++) {
			tempBuffer[tempIndex++] = utf8[k];
		}
		if (jump) {
			shift = !shift;
		}
		i += bytesProcessed;
	}
	strcpy(e.textBuffer, tempBuffer);
	free(tempBuffer);
	return e;
}
etap5 Enigma(etap5 e) {
	int startRotor1=1;
	int startRotor2=1;
	int startRotor3=1;
	if (!e.savewin) {
		DrawTexture(e.enigmawin, 484, 283, WHITE);
		if (e.ennumber[0]) {
			DrawTexture(e.frame, 518, 381, WHITE);
			int letter = GetCharPressed();
			while (letter > 0) {
				if (letter >= 48 && letter <= 57 && e.i_num0 < 2) {
					e.numBuffer0[e.i_num0] = (char)letter;
					e.i_num0++;
					e.numBuffer0[e.i_num0] = '\0';
				}
				letter = GetCharPressed();
			}
			if ((IsKeyPressed(KEY_BACKSPACE) || IsKeyPressedRepeat(KEY_BACKSPACE)) && e.i_num0 > 0) {
				e.i_num0--;
				e.numBuffer0[e.i_num0] = '\0';
			}
			e.finalNumber0 = atoi(e.numBuffer0);
			if (e.enok[0]) {
				if (e.finalNumber0 >= 0 && e.finalNumber0 < 33&&e.numBuffer0[0]!='\0') {
					e.starten[0] = true;
					e.ennumber[0] = false;
					e.enok[0] = false;
				}
				else {
					memset(e.numBuffer0, '\0', 10);
					e.enok[0] = false;
					e.ennumber[0] = false;
					e.i_num0 = 0;
				}
			}
		}
		else if (e.ennumber[1]) {
			DrawTexture(e.frame, 654, 381, WHITE);
			int letter = GetCharPressed();
			while (letter > 0) {
				if (letter >= 48 && letter <= 57 && e.i_num1 < 2) {
					e.numBuffer1[e.i_num1] = (char)letter;
					e.i_num1++;
					e.numBuffer1[e.i_num1] = '\0';
				}
				letter = GetCharPressed();
			}
			if ((IsKeyPressed(KEY_BACKSPACE) || IsKeyPressedRepeat(KEY_BACKSPACE)) && e.i_num1 > 0) {
				e.i_num1--;
				e.numBuffer1[e.i_num1] = '\0';
			}
			e.finalNumber1 = atoi(e.numBuffer1);
			if (e.enok[1]) {
				if (e.finalNumber1 >= 0 && e.finalNumber1 < 33 && e.numBuffer1[0] != '\0') {
					e.starten[1] = true;
					e.ennumber[1] = false;
					e.enok[1] = false;
				}
				else {
					memset(e.numBuffer1, '\0', 10);
					e.enok[1] = false;
					e.ennumber[1] = false;
					e.i_num1 = 0;
				}
			}
		}
		else if (e.ennumber[2]) {
			DrawTexture(e.frame, 790, 381, WHITE);
			int letter = GetCharPressed();
			while (letter > 0) {
				if (letter >= 48 && letter <= 57 && e.i_num2 < 2) {
					e.numBuffer2[e.i_num2] = (char)letter;
					e.i_num2++;
					e.numBuffer2[e.i_num2] = '\0';
				}
				letter = GetCharPressed();
			}
			if ((IsKeyPressed(KEY_BACKSPACE) || IsKeyPressedRepeat(KEY_BACKSPACE)) && e.i_num2 > 0) {
				e.i_num2--;
				e.numBuffer2[e.i_num2] = '\0';
			}
			e.finalNumber2 = atoi(e.numBuffer2);
			if (e.enok[2]) {
				if (e.finalNumber2 >= 0 && e.finalNumber2 < 33 && e.numBuffer2[0] != '\0') {
					e.starten[2] = true;
					e.ennumber[2] = false;
					e.enok[2] = false;
				}
				else {
					memset(e.numBuffer2, '\0', 10);
					e.enok[2] = false;
					e.ennumber[2] = false;
					e.i_num2 = 0;
				}
			}
		}
		if (e.starten[0] && e.starten[1] && e.starten[2]) {
			e.enigmaswtch = false;
		}
	}
	else {
		startRotor1 = e.finalNumber0;
		startRotor2 = e.finalNumber1;
		startRotor3 = e.finalNumber2;
		int len = strlen(e.textBuffer);
		if (len == 0) {
			return;
		}
		int r1[33] = { 8, 15, 22, 1, 30, 12, 5, 27, 19, 3, 25, 10, 2, 17, 29, 14, 6, 21, 32, 9, 24, 0, 11, 28, 20, 4, 26, 13, 7, 23, 31, 16, 18 };
		int r1_inv[33] = { 21, 3, 12, 9, 25, 6, 16, 28, 0, 19, 11, 22, 5, 27, 15, 1, 31, 13, 32, 8, 24, 17, 2, 29, 20, 10, 26, 7, 23, 14, 4, 30, 18 };
		int r2[33] = { 14, 2, 31, 9, 26, 11, 20, 5, 17, 28, 1, 22, 8, 30, 15, 4, 24, 10, 27, 13, 3, 19, 32, 6, 21, 0, 16, 29, 12, 25, 7, 23, 18 };
		int r2_inv[33] = { 25, 10, 1, 20, 15, 7, 23, 30, 12, 3, 17, 5, 28, 19, 0, 14, 26, 8, 32, 21, 6, 24, 11, 31, 16, 29, 4, 18, 9, 27, 13, 2, 22 };
		int reflector[33] = { 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
		int en_r1[26] = { 4, 10, 12, 5, 11, 6, 3, 16, 21, 25, 13, 19, 14, 22, 24, 7, 23, 20, 18, 15, 0, 8, 1, 17, 2, 9 };
		int en_r1_inv[26] = { 20, 22, 24, 6, 0, 3, 5, 15, 21, 25, 1, 4, 2, 10, 12, 19, 7, 23, 18, 11, 17, 8, 13, 16, 14, 9 };
		int en_r2[26] = { 0, 9, 3, 10, 18, 8, 17, 20, 23, 1, 11, 7, 22, 19, 12, 2, 16, 6, 25, 13, 15, 24, 5, 21, 14, 4 };
		int en_r2_inv[26] = { 0, 9, 15, 2, 25, 22, 17, 11, 5, 1, 3, 10, 14, 19, 24, 20, 16, 6, 4, 13, 7, 23, 12, 8, 21, 18 };
		int en_reflector[26] = { 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

		int pos1 = startRotor1 % 33;
		int pos2 = startRotor2 % 33;
		int pos3 = startRotor3 % 33;

		char* tempBuffer = (char*)calloc(len + 10, sizeof(char));
		int tempIndex = 0;
		int i = 0;

		while (i < len) {
			int bytesProcessed = 0;
			int cp = GetCodepoint(&e.textBuffer[i], &bytesProcessed);
			int newCp = cp;

			int charIndexUkr = -1;
			int charIndexEn = -1;
			bool isUpper = false;
			if (cp >= 'A' && cp <= 'Z') { charIndexEn = cp - 'A'; isUpper = true; }
			else if (cp >= 'a' && cp <= 'z') { charIndexEn = cp - 'a'; isUpper = false; }
			else {
				for (int j = 0; j < 33; j++) {
					if (cp == e.ukr_upper[j]) { charIndexUkr = j; isUpper = true; break; }
					if (cp == e.ukr_lower[j]) { charIndexUkr = j; isUpper = false; break; }
				}
			}
			if (charIndexUkr != -1 || charIndexEn != -1) {
				pos1++;
				if (pos1 == 33) {
					pos1 = 0;
					pos2++;
					if (pos2 == 33) {
						pos2 = 0;
						pos3++;
						if (pos3 == 33) pos3 = 0;
					}
				}
				if (charIndexUkr != -1) {
					int c = charIndexUkr;
					c = (r1[(c + pos1) % 33] - (pos1 % 33) + 33) % 33;
					c = (r2[(c + pos2) % 33] - (pos2 % 33) + 33) % 33;
					c = reflector[c];
					c = (r2_inv[(c + pos2) % 33] - (pos2 % 33) + 33) % 33;
					c = (r1_inv[(c + pos1) % 33] - (pos1 % 33) + 33) % 33;
					newCp = isUpper ? e.ukr_upper[c] : e.ukr_lower[c];
				}
				else if (charIndexEn != -1) {
					int c = charIndexEn;
					c = (en_r1[(c + pos1) % 26] - (pos1 % 26) + 26) % 26;
					c = (en_r2[(c + pos2) % 26] - (pos2 % 26) + 26) % 26;
					c = en_reflector[c];
					c = (en_r2_inv[(c + pos2) % 26] - (pos2 % 26) + 26) % 26;
					c = (en_r1_inv[(c + pos1) % 26] - (pos1 % 26) + 26) % 26;
					newCp = isUpper ? 'A' + c : 'a' + c;
				}
			}
			int utf8Size = 0;
			const char* utf8 = CodepointToUTF8(newCp, &utf8Size);
			for (int k = 0; k < utf8Size; k++) {
				tempBuffer[tempIndex++] = utf8[k];
			}
			i += bytesProcessed;
		}

		strcpy(e.textBuffer, tempBuffer);
		free(tempBuffer);
	}
	return e;
}
etap5 XOR(etap5 e) {
	if (!e.savewin) {
		e.fps++;
		DrawTexture(e.xorwin, 484, 283, WHITE);

		int letter = GetCharPressed();
		while (letter > 0) {
			if (letter >= 32 && letter <= 126 && e.keyi < 20) {
				e.keyBuffer[e.keyi] = (char)letter;
				e.keyi++;
				e.keyBuffer[e.keyi] = '\0';
			}
			letter = GetCharPressed();
		}
		if ((IsKeyPressed(KEY_BACKSPACE) || IsKeyPressedRepeat(KEY_BACKSPACE)) && e.keyi > 0) {
			e.keyi--;
			e.keyBuffer[e.keyi] = '\0';
		}
		if (((e.fps / 20) % 3 == 0) || ((e.fps / 20) == 1)) {
			float x;
			float tlenght = MeasureTextEx(e.inter, e.keyBuffer, 24, 2.0f).x;
			x = 540 + tlenght;
			DrawRectangle(x, 405, 12, 3, BLACK);
		}
		if (e.xorok&&e.keyBuffer[0]!='\0') {
			e.keyi = 0;
			strcpy_s(e.KEY, 30, e.keyBuffer);
			memset(e.keyBuffer, '\0', 30);
			e.xorSwitch = false;
			e.xorok = false;
		}
		else {
			e.xorok = false;
		}
	}
	else {
		int len = strlen(e.textBuffer);
		int keyLen = strlen(e.KEY);
		if (len == 0 || keyLen == 0) return;
		for (int i = 0; i < len; i++) {
			char orig = e.textBuffer[i];
			char keyChar = e.KEY[i % keyLen];
			char result = orig ^ keyChar;
			if (orig == '\n' || orig == '\r' || orig == '\0' ||
				result == '\n' || result == '\r' || result == '\0') {
				continue;
			}

			e.textBuffer[i] = result;
		}
	}
	return e;
}
etap5 Trithemius(etap5 e, bool minus) {
	int len = strlen(e.textBuffer);
	if (len == 0) {
		return e;
	}
	char* tempBuffer = (char*)calloc(len + 10, sizeof(char));
	int tempIndex = 0;
	int i = 0;
	int charCount = 1;
	while (i < len) {
		int bytesProcessed = 0;
		int shift = charCount;
		if (minus) {
			shift *= -1;
		}
		int cp = GetCodepoint(&e.textBuffer[i], &bytesProcessed);
		int newCp = cp;
			if (cp >= 'A' && cp <= 'Z') {
				newCp = 'A' + (cp - 'A' + shift % 26 + 26) % 26;
			}
			else if (cp >= 'a' && cp <= 'z') {
				newCp = 'a' + (cp - 'a' + shift % 26 + 26) % 26;
			}
			else {
				bool found = false;
				for (int j = 0; j < 33; j++) {
					if (cp == e.ukr_upper[j]) {
						newCp = e.ukr_upper[(j + shift % 33 + 33) % 33];
						found = true;
						break;
					}
				}if (!found) {
					for (int j = 0; j < 33; j++) {
						if (cp == e.ukr_lower[j]) {
							newCp = e.ukr_lower[(j + shift % 33 + 33) % 33];
							break;
						}
					}
				}
			}
		int utf8Size = 0;
		const char* utf8 = CodepointToUTF8(newCp, &utf8Size);
		for (int k = 0; k < utf8Size; k++) {
			tempBuffer[tempIndex++] = utf8[k];
		}
		i += bytesProcessed;
		charCount++;
	}
	strcpy(e.textBuffer, tempBuffer);
	free(tempBuffer);

	return e;
}
void SaveUndoState(etap5* e) {
	strcpy_s(e->backText2, e->bufferSize, e->backText1);
	e->canUndo2 = e->canUndo1;
	strcpy_s(e->backText1, e->bufferSize, e->backText);
	e->canUndo1 = e->canUndo;
	strcpy_s(e->backText, e->bufferSize, e->textBuffer);
	e->canUndo = true;
}

void CryptFileData(char* text) {
	int len = strlen(text);
	for (int i = 0; i < len; i++) {
		if (text[i] == '\n' || text[i] == '\r') {
			continue;
		}
		if ((text[i] ^ 0x55) != '\0' && text[i] != '\0' &&
			(text[i] ^ 0x55) != 0x1A && text[i] != 0x1A) {
			text[i] = text[i] ^ 0x55;
		}
	}
}
void CypherFile() {
	char* tempText;
	tempText = LoadFileText("text/file1.dms");
	if (tempText != NULL) {
		CryptFileData(tempText);
		SaveFileText("text/file1.dms", tempText);
		UnloadFileText(tempText);
	}
	tempText = LoadFileText("text/file2.dms");
	if (tempText != NULL) {
		CryptFileData(tempText);
		SaveFileText("text/file2.dms", tempText);
		UnloadFileText(tempText);
	}
	tempText = LoadFileText("text/file3.dms");
	if (tempText != NULL) {
		CryptFileData(tempText);
		SaveFileText("text/file3.dms", tempText);
		UnloadFileText(tempText);
	}
	tempText = LoadFileText("text/file4.dms");
	if (tempText != NULL) {
		CryptFileData(tempText);
		SaveFileText("text/file4.dms", tempText);
		UnloadFileText(tempText);
	}
	tempText = LoadFileText("text/file5.dms");
	if (tempText != NULL) {
		CryptFileData(tempText);
		SaveFileText("text/file5.dms", tempText);
		UnloadFileText(tempText);
	}
	tempText = LoadFileText("text/file6.dms");
	if (tempText != NULL) {
		CryptFileData(tempText);
		SaveFileText("text/file6.dms", tempText);
		UnloadFileText(tempText);
	}
	tempText = LoadFileText("text/file7.dms");
	if (tempText != NULL) {
		CryptFileData(tempText);
		SaveFileText("text/file7.dms", tempText);
		UnloadFileText(tempText);
	}
	tempText = LoadFileText("text/policy.dms");
	if (tempText != NULL) {
		CryptFileData(tempText);
		SaveFileText("text/policy.dms", tempText);
		UnloadFileText(tempText);
	}
}
