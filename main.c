#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "name.h"
int main(void) {
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(1366, 768, "Department of Metaphysical Sciences");
	int monitor = GetCurrentMonitor();
	SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
	ToggleFullscreen();
	RenderTexture2D target = LoadRenderTexture(1366, 768);
	InitAudioDevice();
	SetTargetFPS(60);
	int etap = 1;
	CypherFile();
	etap1 a = {0};
	a = Upload1(a);
	etap2 b = LoadGif("gif/logodms.gif");
	etap3 c = { 0 };
	c = Upload3(c);
	etap4 d = { 0 };
	d = Upload4(d);
	etap5 e = { 0 };
	e = Upload5(e);
	while (!WindowShouldClose()) {
		float scale = fminf((float)GetScreenWidth() / 1366.0f, (float)GetScreenHeight() / 768.0f);
		Vector2 mouse = GetMousePosition();
		Vector2 virtualMouse = { 0 };
		virtualMouse.x = (mouse.x - (GetScreenWidth() - (1366 * scale)) * 0.5f) / scale;
		virtualMouse.y = (mouse.y - (GetScreenHeight() - (768 * scale)) * 0.5f) / scale;
		e.virtualMouse = virtualMouse;
		d.virtualMouse = virtualMouse;
		c.virtualMouse = virtualMouse;
		BeginTextureMode(target);
		ClearBackground(BLACK);
		a.fps++;
		if (etap == 1) {
			a = Upload1v(a);
			DrawTexture(a.dms, 58, 39, WHITE);
			DrawTexture(a.usa, 339, 20, WHITE);
			if (CheckCollisionPointRec(virtualMouse, (Rectangle){ 512, 360, 341, 56 })) {
				DrawTexture(a.vvid1, 482, 330, WHITE);
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					a.v = true;
				}
			}
			else {
				DrawTexture(a.vvid, 512, 360, WHITE);
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					a.v = false;
				}
			}
			if (a.v) {
				if (IsKeyPressed(KEY_BACKSPACE)|| IsKeyPressedRepeat(KEY_BACKSPACE)) {
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
				if (CheckCollisionPointRec(virtualMouse, (Rectangle) { 596, 611, 171, 63 })) {
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
				if (CheckCollisionPointRec(virtualMouse, (Rectangle) { 891, 360, 135, 49 })) {
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
			c.hover = CheckCollisionPointRec(virtualMouse, (Rectangle) { 525, 583, 30, 30 });
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
					e.cypherActive[0] = true;
					c.nextb = true;
				}
			}
			else {
				if (CheckCollisionPointRec(virtualMouse, (Rectangle) { 884, 656, 172, 50 }) && c.galochka) {
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
				if (CheckCollisionPointRec(virtualMouse, (Rectangle) { 1107, 656, 172, 50 })) {
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
			if (CheckCollisionPointRec(virtualMouse, (Rectangle) { 55, 507, 100, 95 })) {
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
		}else if(etap==4){
			d = UpdateScrollLogic(d);
			Draw4(d);
			DrawTexture(d.bscroll, 1300, d.scrollY, WHITE);
			BeginScissorMode(28,299, 1310, 425);
				if (d.timef1 > 0) {
					DrawTexture(d.file12, 90, 322 - d.scrollOffset, WHITE);
					d.inf1 = true;
					d.timef1--;
					if (d.timef1 == 0) {
						d.f1 = true;
						etap = 5;

					}
				}
				else {
					if (CheckCollisionPointRec(virtualMouse, (Rectangle) { 86, 320 - d.scrollOffset, 1147, 64 })) {
						if (CheckCollisionPointRec(virtualMouse, (Rectangle) { 28, 299, 1310, 425 })) {
							DrawTexture(d.file11, 56, 290 - d.scrollOffset, WHITE);
							d.inf1 = true;
							if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
								d.timef1 = 5;
							}
						}
					}
					else {
						DrawTexture(d.file1, 86, 320 - d.scrollOffset, WHITE);
						d.inf1 = false;
					}
				}
				if (d.timef2 > 0) {
					DrawTexture(d.file22, 90, 420 - d.scrollOffset, WHITE);
					d.inf2 = true;
					d.timef2--;
					if (d.timef2 == 0) {
						d.f2 = true;
						etap = 5;

					}
				}
				else {
					if (CheckCollisionPointRec(virtualMouse, (Rectangle) { 86, 418 - d.scrollOffset, 1147, 64 })) {
						if (CheckCollisionPointRec(virtualMouse, (Rectangle) { 28, 299, 1310, 425 })) {
							DrawTexture(d.file21, 56, 388 - d.scrollOffset, WHITE);
							d.inf2 = true;
							if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
								d.timef2 = 30;
							}
						}
					}
					else {
						DrawTexture(d.file2, 86, 418 - d.scrollOffset, WHITE);
						d.inf2 = false;
					}
				}
				for (d.i = 0; d.i < 5; d.i++) {
					int resultEtap = DrawFolderButton(&d.folders[d.i], d.scrollOffset,virtualMouse);
					if (resultEtap != 4) {
						etap = resultEtap;
					}
				}

			EndScissorMode();
			if (d.timec > 0) {
				DrawTexture(d.close, 1292, 33, WHITE);
				d.timec--;
				if (d.timec == 0) {
					break;
				}
			}
			else {
				if (CheckCollisionPointRec(virtualMouse, (Rectangle) { 1289, 30, 40, 40 })) {
					DrawTexture(d.close1, 1259, 0, WHITE);

					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
						d.timec = 30;
					}
				}
				else {
					DrawTexture(d.close, 1289, 30, WHITE);
				}
			}
		}
		else if (etap == 5) {
			e.files[0] = d.f1;
			e.files[1] = d.f2;
			e.files[2] = d.folders[0].f;
			e.files[3] = d.folders[1].f;
			e.files[4] = d.folders[2].f;
			e.files[5] = d.folders[3].f;
			e.files[6] = d.folders[4].f;
			Draw5(e);
			if (e.timec > 0) {
				DrawTexture(e.close, 1292, 33, WHITE);
				e.timec--;
				if (e.timec == 0) {
					break;
				}
			}
			else {
				if (CheckCollisionPointRec(virtualMouse, (Rectangle) { 1289, 30, 40, 40 }) && !e.wp&&! e.savewin&&!e.enigmaswtch && !e.xorSwitch) {
					DrawTexture(e.close1, 1259, 0, WHITE);
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
						e.timec = 30;
					}
				}
				else {
					DrawTexture(e.close, 1289, 30, WHITE);
				}
			}
			if (e.timeb > 0) {
				DrawTexture(e.back2, 30, 30, WHITE);
				e.timeb--;
				if (e.timeb == 0) {
					d.f1 = false;
					d.f2 = false;
					d.folders[0].f = false;
					d.folders[1].f = false;
					d.folders[2].f = false;
					d.folders[3].f = false;
					d.folders[4].f = false;
					e.isFileLoaded = false;
					e.scrollY = 0;
					e.dragging = false;
					e.draggingofset = 0;
					e.ratio = 0;
					e.scrolloffset = 0;
					e.edit = false;
					e.cursor = false;
					memset(e.password, 0, 20);
					e.i1 = 0;
					e.save = false;
					memset(e.starten, false, 3);
					memset(e.numBuffer0, '\0', 10);
					memset(e.numBuffer1, '\0', 10);
					memset(e.numBuffer2, '\0', 10);
					memset(e.cypherActive, false, 10);
					e.canUndo = false;
					e.canUndo1 = false;
					e.canUndo2 = false;
					e.cypherActive[0] = true;
					etap = 4;
				}
			}
			else {
				if (CheckCollisionPointRec(virtualMouse, (Rectangle) { 25, 20, 50, 80 }) && !e.wp&&!e.savewin&&!e.enigmaswtch && !e.xorSwitch) {
					DrawTexture(e.back1, 5, 0, WHITE);
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
						e.timeb = 5;
					}
				}
				else {
					DrawTexture(e.back, 25, 20, WHITE);
				}
			}
			if (e.isFileLoaded == false && etap == 5) {
				e = textfile(e);
				e.k = strlen(e.textBuffer);
			}
			e.texth = MeasureTextEx(e.inter, e.textBuffer, 26, 2.0f).y;
			e.maxScroll = e.texth + 100;
			if (!e.wp&&!e.savewin&&!e.enigmaswtch&&!e.xorSwitch) {
				e = Scrollogic(e);
			}
			BeginScissorMode(10, 168, 1346, 584);
			if (e.cursor) {
				DrawRectangle(e.x, e.cursorY+2, 12, 3, RAYWHITE);
			}
			DrawTextEx(e.inter, e.textBuffer, (Vector2) { 30, 180 - e.scrolloffset }, 26, 2.0f, RAYWHITE);
			DrawTexture(e.bscroll, 1325, e.scrollY, WHITE);
			EndScissorMode();
			if (e.savetime > 0) {
				DrawTexture(e.saveb3, 0, 717, WHITE);
				e.savetime--;
			}
			if (e.savewin) {
				e = SaveWindow(e);
			}
			else {
				if (CheckCollisionPointRec(virtualMouse, (Rectangle) { 1065, 56, 172, 50 }) && !e.wp&&e.save&&!e.enigmaswtch && !e.xorSwitch) {
					DrawTexture(e.saveb1, 1035, 26, WHITE);
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
						e.savewin = true;
					}
				}
				else {
					DrawTexture(e.saveb, 1065, 56, WHITE);
				}
			}
			if (e.edit&&!e.enigmaswtch&&!e.xorSwitch) {
				if (IsKeyPressed(KEY_BACKSPACE) || IsKeyPressedRepeat(KEY_BACKSPACE)) {
					e.bs = true;
				}
				else {
					e.bs = false;
				}
				if (IsKeyPressed(KEY_ENTER)) {
					e.enter = true;
				}
				else {
					e.enter = false;
				}
				if (IsKeyPressed(KEY_LEFT) || IsKeyPressedRepeat(KEY_LEFT)) {
					e.left = true;
				}
				else {
					e.left = false;
				}
				if (IsKeyPressed(KEY_RIGHT) || IsKeyPressedRepeat(KEY_RIGHT)) {
					e.right = true;
				}
				else {
					e.right = false;
				}
				if (IsKeyPressed(KEY_UP) || IsKeyPressedRepeat(KEY_UP)) {
					e.up = true;
				}
				else {
					e.up = false;
				}
				if (IsKeyPressed(KEY_DOWN) || IsKeyPressedRepeat(KEY_DOWN)) {
					e.down = true;
				}
				else {
					e.down = false;
				}
				e = editmode(e);
				if ((((a.fps / 20) % 3) == 0) || (((a.fps / 20) % 3) == 1)) {
					float lineH = MeasureTextEx(e.inter, "A", 28, 2.0f).y;
					e.cursorY = (180 - e.scrolloffset) + ((e.linecout - 1) * lineH) + 14;
					e.cursor = true;
				}
				else {
					e.cursor = false;
				}
			}
			else {
				if (!e.enigmaswtch && !e.xorSwitch) {
					DrawTexture(e.novedit, 0, 112, WHITE);
				}
				if (e.wp) {
					DrawTexture(e.winp, 0, 552, WHITE);
					e = editpassword(e);
					DrawTextEx(e.inter, e.password, (Vector2) { 175, 645 }, 24, 2.0f, BLACK);
				}
				else {
					if (CheckCollisionPointRec(virtualMouse, (Rectangle) { 1172, 117, 146, 38 }) && !e.enigmaswtch&&!e.xorSwitch) {
						DrawTexture(e.editb1, 1142, 87, WHITE);
						if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
							e.wp = true;
							e.i1 = 0;
						}
					}
					else {
						if (!e.enigmaswtch && !e.xorSwitch) {
							DrawTexture(e.editb, 1172, 117, WHITE);
						}
					}
				}
			}
			if (e.enigmaswtch) {
				e=Enigma(e);
				DrawTextEx(e.inter, e.numBuffer0, (Vector2) { 540, 388 }, 24, 2.0f, BLACK);
				DrawTextEx(e.inter, e.numBuffer1, (Vector2) { 676, 388 }, 24, 2.0f, BLACK);
				DrawTextEx(e.inter, e.numBuffer2, (Vector2) { 812, 388 }, 24, 2.0f, BLACK);
				if (CheckCollisionPointRec(virtualMouse, (Rectangle) { 521, 384, 68, 30 })&&!e.starten[0]) {
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
						memset(e.ennumber, false, 3);
						e.ennumber[0] = true;
					}
				}
				else {
				}
				if (CheckCollisionPointRec(virtualMouse, (Rectangle) { 657, 384, 68, 30 })&&!e.starten[1]) {
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
						memset(e.ennumber, false, 3);
						e.ennumber[1] = true;
					}
				}
				if (CheckCollisionPointRec(virtualMouse, (Rectangle) { 793, 384, 68, 30 })&&!e.starten[2]) {
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
						memset(e.ennumber, false, 3);
						e.ennumber[2] = true;
					}
				}
				else {
				}
				if (CheckCollisionPointRec(virtualMouse, (Rectangle) { 505, 426, 100, 32 })&&!e.starten[0]&& e.ennumber[0]) {
					DrawTexture(e.ok5b1, 505,426, WHITE);

					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
						e.enok[0] = true;
					}
				}
				else {
					DrawTexture(e.ok5b, 505, 426, WHITE);
				}
				if (CheckCollisionPointRec(virtualMouse, (Rectangle) { 641, 426, 100, 32 }) && !e.starten[1]&& e.ennumber[1]) {
					DrawTexture(e.ok5b1, 641, 426, WHITE);

					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
						e.enok[1] = true;
					}
				}
				else {
					DrawTexture(e.ok5b, 641, 426, WHITE);
				}
				if (CheckCollisionPointRec(virtualMouse, (Rectangle) { 777, 426, 100, 32 }) && !e.starten[2]&& e.ennumber[2]) {
					DrawTexture(e.ok5b1, 777, 426, WHITE);

					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
						e.enok[2] = true;
					}
				}
				else {
					DrawTexture(e.ok5b, 777, 426, WHITE);
				}
			}
			if (e.xorSwitch) {
				e = XOR(e);
				DrawTextEx(e.inter, e.keyBuffer, (Vector2) { 538, 388 }, 24, 2.0f, BLACK);
				if (CheckCollisionPointRec(virtualMouse, (Rectangle) { 777, 426, 100, 32 })) {
					DrawTexture(e.ok5b1, 777, 426, WHITE);
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
						e.xorok = true;
					}
				}
				else {
					DrawTexture(e.ok5b, 777, 426, WHITE);
				}
			}
			if (e.cyp) {
				e = Cypherbutton(e);
			}
			if (CheckCollisionPointRec(virtualMouse, (Rectangle) { 127, 63, 217, 30 })&& !e.wp&&! e.savewin&&!e.enigmaswtch&&!e.xorSwitch) {
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					if (!e.cyp) {
						e.cyp = true;
					}
					else {
						e.cyp = false;
					}
				}
			}
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				if (!CheckCollisionPointRec(virtualMouse, (Rectangle) { 97, 33, 277, 386 })) {
					e.cyp = false;
				}
			}
			if (!e.cyp) {
				DrawTexture(e.cypher, 319, 72, WHITE);
				cypheractived(e);
			}
		}
		EndTextureMode();
		BeginDrawing();
		ClearBackground(BLACK);
		DrawTexturePro(target.texture,(Rectangle) {0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height},
			(Rectangle) {(GetScreenWidth() - ((float)1366 * scale)) * 0.5f,
			(GetScreenHeight() - ((float)768 * scale)) * 0.5f, (float)1366 * scale, (float)768 * scale},
			(Vector2) {0, 0}, 0.0f, WHITE);
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
	UnloadTexture(d.fon);
	UnloadTexture(d.dms);
	UnloadTexture(d.field);
	UnloadTexture(d.scroll);
	UnloadTexture(d.bscroll);
	UnloadTexture(d.file1);
	UnloadTexture(d.infofile1);
	UnloadTexture(d.file11);
	UnloadTexture(d.file12);
	UnloadTexture(d.file2);
	UnloadTexture(d.infofile2);
	UnloadTexture(d.file21);
	UnloadTexture(d.file22);
	UnloadTexture(d.close);
	UnloadTexture(d.close1);
	UnloadTexture(d.close2);
	for (d.i = 0; d.i < 5; d.i++) {
		UnloadTexture(d.folders[d.i].file);
		UnloadTexture(d.folders[d.i].file1);
		UnloadTexture(d.folders[d.i].file2);
	}
	UnloadTexture(e.fon);
	UnloadTexture(e.novebar);
	UnloadTexture(e.novedit);
	UnloadTexture(e.scroll);
	UnloadTexture(e.bscroll);
	UnloadTexture(e.close);
	UnloadTexture(e.close1);
	UnloadTexture(e.close2);
	UnloadTexture(e.back);
	UnloadTexture(e.back1);
	UnloadTexture(e.back2);
	UnloadTexture(e.editb);
	UnloadTexture(e.editb1);
	UnloadTexture(e.winp);
	UnloadTexture(e.continueb);
	UnloadTexture(e.continueb1);
	UnloadTexture(e.exit);
	UnloadTexture(e.exit1);
	UnloadTexture(e.saveb);
	UnloadTexture(e.saveb1);
	UnloadTexture(e.saveb2);
	UnloadTexture(e.saveb3);
	UnloadTexture(e.textf1);
	UnloadTexture(e.textf2);
	UnloadTexture(e.textf3);
	UnloadTexture(e.textf4);
	UnloadTexture(e.textf5);
	UnloadTexture(e.textf6);
	UnloadTexture(e.textf7);
	UnloadTexture(e.winp);
	UnloadTexture(e.continueb);
	UnloadTexture(e.continueb1);
	UnloadTexture(e.exit);
	UnloadTexture(e.exit1);
	UnloadTexture(e.saveb);
	UnloadTexture(e.saveb1);
	UnloadTexture(e.saveb2);
	UnloadTexture(e.saveb3);
	UnloadTexture(e.cypherrr);
	UnloadTexture(e.cypher);
	UnloadTexture(e.cypher1);
	UnloadTexture(e.cypher2);
	UnloadTexture(e.cypher3);
	UnloadTexture(e.cypher4);
	UnloadTexture(e.cypher2act);
	UnloadTexture(e.cypher3act);
	UnloadTexture(e.cypher4act);
	UnloadTexture(e.savewindow);
	UnloadTexture(e.cencel5b);
	UnloadTexture(e.cencel5b1);
	UnloadTexture(e.ok5b);
	UnloadTexture(e.ok5b1);
	UnloadTexture(e.enigmawin);
	UnloadTexture(e.frame);
	UnloadTexture(e.xorwin);
	memset(e.tempLine, 0, sizeof(e.tempLine));
	if(e.textBuffer != NULL) {
		free(e.textBuffer);
	}
	if (e.backText != NULL) {
		free(e.backText);
	}
	if (e.backText1 != NULL) {
		free(e.backText1);
	}
	if (e.backText2 != NULL) {
		free(e.backText2);
	}
	CypherFile();
	CloseWindow();
}
