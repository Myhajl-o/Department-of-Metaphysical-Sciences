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
	c.fon = LoadTexture("images/fon.png");
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
	c.scrol = LoadTexture("images/scroll.png");
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
