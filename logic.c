#define _CRT_SECURE_NO_WARNINGS
#include <raylib.h>
#include <string.h>
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
	strcpy_s(a.password,100, "apple");
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
	c.loadText=LoadFileText("text/policy.txt");
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
	if (!c.dragging&&CheckCollisionPointRec(GetMousePosition(), (Rectangle) { 545, 101, 622, 407 })) {
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
		if (CheckCollisionPointRec(GetMousePosition(), (Rectangle) { 1190, c.scrollBarY-20, 30, 20 })) {
			c.dragging = true;
			c.draggingofset = GetMouseY() - c.scrollBarY;
		}
	}
	if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
		c.dragging = false;
	}
	if (c.dragging) {
		c.newSliderY = GetMouseY() - c.draggingofset;
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
	if (d.wheel != 0) {
		d.scrollOffset -= d.wheel * 40.0f;
	}
	if (d.scrollOffset < 0) {
		d.scrollOffset = 0;
	}
	d.maxScroll = 500.0f;
	if (d.scrollOffset > d.maxScroll) {
		d.scrollOffset = d.maxScroll;
	}
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		if (CheckCollisionPointRec(GetMousePosition(), (Rectangle) {1300,d.scrollY,25,58})) {
			d.dragging = true;
			d.draggingofset = GetMouseY() - d.scrollY;
		}
	}
	if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
		d.dragging = false;
	}
	if (d.dragging) {
		d.scrollY = GetMouseY() - d.draggingofset;
		if (d.scrollY < 334) {
			d.scrollY = 334;
		}if (d.scrollY > 629) {
			d.scrollY = 629;
		}

		d.ratio = (d.scrollY - 334) / 295.0f;
		d.scrollOffset = d.ratio * d.maxScroll;
	}
	else {
		if (d.scrollOffset < 0) d.scrollOffset = 0;
		if (d.scrollOffset > d.maxScroll) d.scrollOffset = d.maxScroll;
		d.ratio = d.scrollOffset / d.maxScroll;
		d.scrollY = 334 + (d.ratio * 295.0f);
	}
	return d;
}
int DrawFolderButton(FolderButton* btn, float scrollOffset) {
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
		if (CheckCollisionPointRec(GetMousePosition(), (Rectangle) { 86, screenY-20, 1147, 64 })) {
			if (CheckCollisionPointRec(GetMousePosition(), (Rectangle) { 28, 299, 1310, 425 })) {
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
	strcpy_s(e.password1, 20, "UWU");
	memset(e.password, 0, 20);
	e.ok = false;
	e.correct = false;
	e.i1 = 0;
	e.times = 0;
	e.save = false;
	return e;
}
void Draw5(etap5 e,bool f1, bool f2, bool f3, bool f4, bool f5, bool f6, bool f7) {
	DrawTexture(e.fon, 0, 0, WHITE);
	DrawTexture(e.novebar, 0, 0, WHITE);
	DrawTexture(e.scroll, 1325, 180, WHITE);
	if (f1) {
		DrawTexture(e.textf1, 391, 25, WHITE);
	}
	else if (f2) {
		DrawTexture(e.textf2, 313, 25, WHITE);
	}
	else if (f3) {
		DrawTexture(e.textf3, 562, 25, WHITE);
	}
	else if (f4) {
		DrawTexture(e.textf4, 562, 25, WHITE);
	}
	else if (f5) {
		DrawTexture(e.textf5, 562, 25, WHITE);
	}
	else if (f6) {
		DrawTexture(e.textf6, 562, 25, WHITE);
	}
	else if (f7) {
		DrawTexture(e.textf7, 562, 25, WHITE);
	}
}
etap5 Scrollogic(etap5 e) {
	e.wheel = GetMouseWheelMove();
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		if (CheckCollisionPointRec(GetMousePosition(), (Rectangle) { 1325, e.scrollY-20, 25, 58 })) {
			e.dragging = true;
			e.draggingofset = GetMouseY() - e.scrollY;
		}
	}
	if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
		e.dragging = false;
	}
	if (e.dragging) {
		e.scrollY = GetMouseY() - e.draggingofset;
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
etap5 textfile(etap5 e,bool f1,bool f2,bool f3, bool f4, bool f5, bool f6, bool f7) {
	memset(e.textBuffer, 0, sizeof(e.textBuffer));
	char* tempText = NULL;
	if (f1) {
		tempText = LoadFileText("text/file1.txt");
	}
	else if (f2) {
		tempText = LoadFileText("text/file2.txt");
	}
	else if (f3) {
		tempText = LoadFileText("text/file3.txt");
	}
	else if (f4) {
		tempText = LoadFileText("text/file4.txt");
	}
	else if (f5) {
		tempText = LoadFileText("text/file5.txt");
	}
	else if (f6) {
		tempText = LoadFileText("text/file6.txt");
	}
	else if (f7) {
		tempText = LoadFileText("text/file7.txt");
	}
	if (tempText != NULL) {
		strcpy(e.textBuffer, tempText);
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
			e.currentline += MeasureTextEx(e.inter, e.tempt, 20, 2.0f).x+2.0f;

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
		if (e.letter >= 32 && e.len < 20400) {
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

	if (e.enter && e.len < 20400) {
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
		e.x = 32 + MeasureTextEx(e.inter, e.tempLine, 20, 2.0f).x;
	}
	else {
		e.x = 32;
	}

	return e;
}
etap5 editpassword(etap5 e) {
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
		if (e.i1 > 0) {
			e.i1--;
			e.password[e.i1] = '\0';
		}
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
		if (CheckCollisionPointRec(GetMousePosition(), (Rectangle) { 135, 697, 100, 32 })) {
			DrawTexture(e.continueb1, 135, 717, WHITE);
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				e.correct = true;
			}
		}
		else {
			DrawTexture(e.continueb, 135, 717, WHITE);
		}
	}
	if (CheckCollisionPointRec(GetMousePosition(), (Rectangle) { 344, 697, 100, 32 })) {
		DrawTexture(e.exit1, 344, 717, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			e.wp = false;
		}
	}
	else {
		DrawTexture(e.exit, 344, 717, WHITE);
	}
	return e;
}
void Savefile(etap5 e, bool f1, bool f2, bool f3, bool f4, bool f5, bool f6, bool f7) {
	if (f1) {
		SaveFileText("text/file1.txt", e.textBuffer);
	}
	else if (f2) {
		SaveFileText("text/file2.txt", e.textBuffer);
	}
	else if (f3) {
		SaveFileText("text/file3.txt", e.textBuffer);
	}
	else if (f4) {
		SaveFileText("text/file4.txt", e.textBuffer);
	}
	else if (f5) {
		SaveFileText("text/file5.txt", e.textBuffer);
	}
	else if (f6) {
		SaveFileText("text/file6.txt", e.textBuffer);
	}
	else if (f7) {
		SaveFileText("text/file7.txt", e.textBuffer);
	}
}
