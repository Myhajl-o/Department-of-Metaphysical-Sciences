#include <raylib.h>
#include <stdio.h>
#include <string.h>
#include "name.h"
int main(void) {
	InitWindow(1366, 768, "Department of Metaphysical Sciences");
	InitAudioDevice();
	SetTargetFPS(60);
	int etap = 1;
	etap1 a = {0};
	a = Upload1(a);
	etap2 b = LoadGif("gif/logodms.gif");
	etap3 c = { 0 };
	c = Upload3(c);
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);
		a.fps++;
		if (etap == 1) {
			a = Upload1v(a);
			DrawTexture(a.dms, 58, 39, WHITE);
			DrawTexture(a.usa, 339, 20, WHITE);
			if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){ 513, 341, 341, 56 })) {
				DrawTexture(a.vvid1, 482, 330, WHITE);
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					SetMouseCursor(MOUSE_CURSOR_IBEAM);
					a.v = true;
				}
			}
			else {
				SetMouseCursor(MOUSE_CURSOR_DEFAULT);
				DrawTexture(a.vvid, 512, 360, WHITE);
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					a.v = false;
				}
			}
			if (a.v) {
				if (IsKeyPressed(KEY_BACKSPACE)) {
					a.vb = true;
				}
				else {
					a.vb = false;
				}
				if ((((a.fps / 20) % 3) == 0)|| (((a.fps / 20) % 3) == 1)) {
					DrawRectangle(a.x, 395, 15, 7, YELLOW);
				}
			}
			DrawTextEx(a.inter, a.password1, (Vector2) { 522, 375 }, 32, 1, YELLOW);
			if (a.timee > 0) {
				DrawTexture(a.exit2, 601, 616, WHITE);
				a.timee--;
				if (a.timee == 0) {
					a.e = true;
				}
			}
			else {
				if (CheckCollisionPointRec(GetMousePosition(), (Rectangle) { 597, 592, 171, 63 })) {
					DrawTexture(a.exit1, 566, 581, WHITE);
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
						if (a.rub == 0) {
							a.rub = 1;
							a.timee = 5;
							a.fps = 0;
						}
					}
				}
				else {
					DrawTexture(a.exit, 596, 611, WHITE);
				}
			}
			if (a.e && a.fps == 60) {
				break;
			}
			if (a.time > 0) {
				DrawTexture(a.con2, 896, 365, WHITE);
				a.time--;
				if (a.time == 0) {
					a.c1 = true;
					a.cp1 = true;
				}
			}
			else {
				if (CheckCollisionPointRec(GetMousePosition(), (Rectangle) { 892, 341, 135, 49 })) {
					DrawTexture(a.con1, 861, 330, WHITE);
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
						if (a.time == 0) {
							a.time = 5;
						}
					}
				}
				else {
					DrawTexture(a.con, 891, 360, WHITE);
				}
			}
			if (a.pere) {
				a.peret--;
				if (a.peret == 0) {
					etap = 2;
					a.pere = false;
				}
			}
		}
		else if (etap == 2) {
			if (a.cp1) {
				a.fps = 0;
				a.cp1 = false;
			}
			if (a.fps == 210) {
				PlaySound(b.codmw2);
			}
			if (a.fps >= 300) {
				b = UpdateGif(b);
				DrawGif(b);
			}
			if ((b.f == b.totalf - 1)&&a.fps>=1200) {
				etap = 3;
			}
		}
		else if (etap==3) {
			DrawTexture(c.fon, 0, 0, WHITE);
			DrawTexture(c.dms, 36, 16, WHITE);
			DrawTexture(c.textfield, 518, 72, WHITE);
			c.hover = CheckCollisionPointRec(GetMousePosition(), (Rectangle) { 525, 563, 30, 30 });
			if (c.hover && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				c.galochka = !c.galochka;
			}
			if (c.hover) {
				if (c.galochka) {
					DrawTexture(c.accept3, 495, 553, WHITE);
				}
				else {
					DrawTexture(c.accept1, 495, 553, WHITE);
				}
			}
			else {
				if (c.galochka) {
					DrawTexture(c.accept2, 525, 583, WHITE);
				}
				else {
					DrawTexture(c.accept, 525, 583, WHITE);
				}
			}
			if (c.timern > 0) {
				DrawTexture(c.next2, 889, 659, WHITE);
				c.timern--;
				if (c.timern == 0) {
					a.fps = 0;
					c.nextb = true;
				}
			}
			else {
				if (CheckCollisionPointRec(GetMousePosition(), (Rectangle) { 884, 636, 172, 50 }) && c.galochka) {
					DrawTexture(c.next1, 854, 626, WHITE);
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
						if (c.rub == false) {
							c.timern = 5;
							c.rub = true;
						}
					}
				}
				else {
					DrawTexture(c.next, 884, 656, WHITE);
				}
			}
			if (c.nextb && a.fps == 60) {
				etap = 4;
			}
			if (c.timerc > 0) {
				DrawTexture(c.cencel2, 1112, 659, WHITE);
				c.timerc--;
				if (c.timerc == 0) {
					a.fps = 0;
					c.cencelb = true;
				}
			}
			else {
				if (CheckCollisionPointRec(GetMousePosition(), (Rectangle) { 1107, 636, 172, 50 })) {
					DrawTexture(c.cencel1, 1077, 626, WHITE);
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
						if (c.rub == false) {
							c.timerc = 5;
							c.rub = true;
						}
					}
				}
				else {
					DrawTexture(c.cencel, 1107, 656, WHITE);
				}
			}
			if (c.cencelb && a.fps == 60) {
				break;
			}
			c = Drawtext (c);
			UpdateMusicStream(c.autext);
			if (CheckCollisionPointRec(GetMousePosition(), (Rectangle) { 55, 487, 100, 95 })) {
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					if (c.onoff) {
						c.onoff = false;
					}
					else {
						c.onoff = true;
					}
				}
			}
			if (c.onoff) {
				ResumeMusicStream(c.autext);
				DrawTexture(c.audiob, 55, 507, WHITE);
				c.fps++;
				if (c.fps % 60 == 0) {
					c.tick++;
				}
			}
			else {
				PauseMusicStream(c.autext);
				DrawTexture(c.audiob1, 55, 507, WHITE);
			}
			DrawTexture(c.povzunok, 198, 592, WHITE);
			c.x = (c.tick / 1108.0f) * 300;
			DrawTexture(c.povzunok1, 193+c.x, 588, WHITE);
			DrawTextEx(c.mono, "18:28", (Vector2) { 422, 546 }, 28, 2, WHITE);
			c.minutes = c.tick / 60;
			c.seconds = c.tick % 60;
			DrawTextEx(c.mono, TextFormat("%02d:%02d",c.minutes,c.seconds), (Vector2) { 182, 546 }, 28, 2, WHITE);
		}
		EndDrawing();
	}
	UnloadTexture(a.dms);
	UnloadTexture(a.usa);
	UnloadTexture(a.con);
	UnloadTexture(a.exit);
	UnloadTexture(a.vvid);
	UnloadTexture(a.con1);
	UnloadTexture(a.exit1);
	UnloadTexture(a.vvid1);
	UnloadTexture(a.con2);
	UnloadTexture(a.exit2);
	UnloadSound(a.err);
	UnloadSound(a.good);
	UnloadFont(a.inter);
	UnloadTexture(b.giph);
	UnloadImage(b.gif);
	UnloadSound(b.codmw2);
	UnloadTexture(c.dms);
	UnloadTexture(c.textfield);
	UnloadTexture(c.accept);
	UnloadTexture(c.next);
	UnloadTexture(c.cencel);
	UnloadTexture(c.scrol);
	UnloadTexture(c.accept1);
	UnloadTexture(c.accept2);
	UnloadTexture(c.accept3);
	UnloadTexture(c.next1);
	UnloadTexture(c.next2);
	UnloadTexture(c.cencel1);
	UnloadTexture(c.cencel2);
	UnloadFileText(c.policy);
	UnloadMusicStream(c.autext);
	UnloadTexture(c.audiob);
	UnloadTexture(c.audiob1);
	CloseAudioDevice();
	CloseWindow();
}
