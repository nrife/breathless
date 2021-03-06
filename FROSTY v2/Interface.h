#pragma once
#include "Configuration.hpp"
#include "dropboxes.h"
#include "Variables.h"
#include "Themes.h"
#include <cctype>
#include "Logging.h"
#include "Listener.h"



#define RandomInt(nMin, nMax) (rand() % (nMax - nMin + 1) + nMin);
#define IM_ARRAYSIZE(_ARR)  ((int)(sizeof(_ARR)/sizeof(*_ARR)))
#define BUILDSTAMP ( __DATE__ )
typedef void(*CL_FullUpdate_t) (void);
CL_FullUpdate_t CL_FullUpdate = nullptr;


void FullUpdate()
{
	static auto CL_FullUpdate = reinterpret_cast<CL_FullUpdate_t>(U::FindPattern("engine.dll", reinterpret_cast<PBYTE>("\xA1\x00\x00\x00\x00\xB9\x00\x00\x00\x00\x56\xFF\x50\x14\x8B\x34\x85"), "x????x????xxxxxxx"));
	CL_FullUpdate();
}

//--------------------------------------------
//Weapon CFG stuff	

const char* weaponnames(int id)
{
	switch (id)
	{
	case 1:
		return "deagle";
	case 2:
		return "elite";
	case 3:
		return "fiveseven";
	case 4:
		return "glock";
	case 7:
		return "ak47";
	case 8:
		return "aug";
	case 9:
		return "awp";
	case 10:
		return "famas";
	case 11:
		return "g3sg1";
	case 13:
		return "galilar";
	case 14:
		return "m249";
	case 60:
		return "m4a1_silencer";
	case 16:
		return "m4a1";
	case 17:
		return "mac10";
	case 19:
		return "p90";
	case 24:
		return "ump45";
	case 25:
		return "xm1014";
	case 26:
		return "bizon";
	case 27:
		return "mag7";
	case 28:
		return "negev";
	case 29:
		return "sawedoff";
	case 30:
		return "tec9";
	case 32:
		return "hkp2000";
	case 33:
		return "mp7";
	case 34:
		return "mp9";
	case 35:
		return "nova";
	case 36:
		return "p250";
	case 38:
		return "scar20";
	case 39:
		return "sg556";
	case 40:
		return "ssg08";
	case 61:
		return "usp_silencer";
	case 63:
		return "cz75a";
	case 64:
		return "revolver";
	case 508:
		return "knife_m9_bayonet";
	case 500:
		return "bayonet";
	case 505:
		return "knife_flip";
	case 506:
		return "knife_gut";
	case 507:
		return "knife_karambit";
	case 509:
		return "knife_tactical";
	case 512:
		return "knife_falchion";
	case 514:
		return "knife_survival_bowie";
	case 515:
		return "knife_butterfly";
	case 516:
		return "knife_push";

	default:
		return "";
	}
}

bool IsUtility(ItemDefinitionIndexx index)
{
	switch (index)
	{
	case ItemDefinitionIndexx::ITEM_NONE:
	case ItemDefinitionIndexx::WEAPON_C4:
	case ItemDefinitionIndexx::WEAPON_FLASH:
	case ItemDefinitionIndexx::WEAPON_HE:
	case ItemDefinitionIndexx::WEAPON_INC:
	case ItemDefinitionIndexx::WEAPON_MOLOTOV:
	case ItemDefinitionIndexx::WEAPON_SMOKE:
	case ItemDefinitionIndexx::WEAPON_DECOY:
	case ItemDefinitionIndexx::WEAPON_KNIFE_T:
	case ItemDefinitionIndexx::WEAPON_KNIFE_CT:
	case ItemDefinitionIndexx::GLOVE_T_SIDE:
	case ItemDefinitionIndexx::GLOVE_CT_SIDE:
	case ItemDefinitionIndexx::GLOVE_SPORTY:
	case ItemDefinitionIndexx::GLOVE_SLICK:
	case ItemDefinitionIndexx::GLOVE_LEATHER_WRAP:
	case ItemDefinitionIndexx::GLOVE_STUDDED_BLOODHOUND:
	case ItemDefinitionIndexx::GLOVE_MOTORCYCLE:
	case ItemDefinitionIndexx::GLOVE_SPECIALIST:
		return true;
	default:
		return false;
	}
}

bool Contains(const std::string &word, const std::string &sentence) {
	if (word == "" || sentence == "")
		return true;

	return sentence.find(word) != std::string::npos;
}

std::string ToLower(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), (int(*)(int))std::tolower);

	return str;
}
//--------------------------------------------
bool defaultk;
bool bayonet;
bool flip;
bool gut;
bool karambit;
bool m9bayonet;
bool huntsman;
bool falchion;
bool bowie;
bool butterfly;
bool daggers;

void doknives(bool* disknife)
{
	defaultk = false;
	bayonet = false;
	flip = false;
	gut = false;
	karambit = false;
	m9bayonet = false;
	huntsman = false;
	falchion = false;
	bowie = false;
	butterfly = false;
	daggers = false;

	*disknife = true;
}

const char* HitmarkSound[] =
{
	"Disabled",
	"Default",
	"Roblox",
	"Trump",
	"Metallic"
};

const char* AngleStyles[] =
{
	"Disabled",
	"Ground",
	"Crosshair"
};

const char* ClanTags[] =
{
	"none",
	"breathless",
	"gamesense",
};

static float goddamnalpha = 0.f;

void RenderInterface() {

	
	bool is_renderer_active = renderer->IsActive();

	if (is_renderer_active)
	{
		g_Options.Menu.bShowTabs = true;
	}
	else
	{
		g_Options.Menu.bShowTabs = false;
	}

	if (is_renderer_active)
	{

		if (Globals::error)
		{
			ImGui::SetNextWindowPosCenter(ImGuiSetCond_Appearing);
			ImGui::SetNextWindowSize(ImVec2(200, 50));
			if (ImGui::Begin(XorStr("Warning!"), &g_Options.Menu.Opened, ImVec2(400, 200), 1.f, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_ShowBorders))
			{
				ImGui::Text(XorStr("ah ah ahhh! one at a time please!"));
				if (ImGui::Button(XorStr("OK!")))
				{
					if (g_Options.Ragebot.error_type == 1)
					{
						g_Options.Ragebot.run_PreAAs = false;
						g_Options.Ragebot.run_BuilderAAs = false;
						Globals::error = false;
						g_Options.Ragebot.error_type == 0;
					}
					else if (g_Options.Ragebot.error_type == 2)
					{
						g_Options.Ragebot.walk_PreAAs = false;
						g_Options.Ragebot.walk_BuilderAAs = false;
						Globals::error = false;
						g_Options.Ragebot.error_type == 0;
					}
					else if (g_Options.Ragebot.error_type == 3)
					{
						g_Options.Ragebot.crouch_PreAAs = false;
						g_Options.Ragebot.crouch_BuilderAAs = false;
						Globals::error = false;
						g_Options.Ragebot.error_type == 0;
					}
					else if (g_Options.Ragebot.error_type == 4)
					{
						g_Options.Ragebot.fwalk_PreAAs = false;
						g_Options.Ragebot.fwalk_BuilderAAs = false;
						Globals::error = false;
						g_Options.Ragebot.error_type == 0;
					}
					else if (g_Options.Ragebot.error_type == 5)
					{
						g_Options.Ragebot.stand_PreAAs = false;
						g_Options.Ragebot.stand_BuilderAAs = false;
						Globals::error = false;
						g_Options.Ragebot.error_type == 0;
					}
				}
			}ImGui::End();
		}
	


		if (ImGui::Begin("##chet", &is_renderer_active, ImVec2(750, 608), 1.f, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse))
		{
			static float r = 1.0f;
			static float g = 0.f;
			static float b = 0.f;

			if (r == 1.f && g >= 0.f && b <= 0.f)
			{
				g += 0.005f;
				b = 0.f;
			}
			if (r <= 1.f && g >= 1.f && b == 0.f)
			{
				g = 1.f;
				r -= 0.005f;
			}
			if (r <= 0.f && g == 1.f && b >= 0.f)
			{
				r = 0.f;
				b += 0.005f;
			}
			if (r == 0.f && g <= 1.f && b >= 1.f)
			{
				b = 1.f;
				g -= 0.005f;
			}
			if (r >= 0.f && g <= 0.f && b == 1.f)
			{
				g = 0.f;
				r += 0.005f;
			}
			if (r >= 1.f && g >= 0.f && b <= 1.f)
			{
				r = 1.f;
				b -= 0.005f;
			}

			ImGui::PushStyleColor(ImGuiCol_ChildWindowBg, ImVec4(r, g, b, 1.f));

			ImGui::BeginChild("##rainbotcrapnignog", ImVec2(733.f, 3.f));
			ImGui::EndChild();
			ImGui::PopStyleColor();

			ImGui::Spacing();
			
			static int tabselected = 0;
			ImGui::BeginChild("##tabshit", ImVec2(100.f, 580.f));
			{
				ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.07, 0.07, 0.07, 1.f));
				ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.07, 0.07, 0.07, 1.f));
				ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.07, 0.07, 0.07, 1.f));
				ImGui::PushStyleColor(ImGuiCol_ChildWindowBg, ImVec4(0.07f, 0.07f, 0.07f, 1.f));
				ImGui::PushFont(fskeet);
				if (ImGui::Button(u8"暴力", ImVec2(100, 93)))
					tabselected = 0;
				if (ImGui::Button(u8"微自瞄", ImVec2(100, 93)))
					tabselected = 1;
				if (ImGui::Button(u8"视觉", ImVec2(100, 93)))
					tabselected = 2;
				if (ImGui::Button(u8"杂项", ImVec2(100, 93)))
					tabselected = 3;
				if (ImGui::Button("e", ImVec2(100, 93)))
					tabselected = 4; 
				if (ImGui::Button("f", ImVec2(100, 91)))
					tabselected = 5;
				ImGui::PopFont();
				

			}
			ImGui::EndChild();

			ImGui::SameLine();
			
			ImGui::BeginChild("##b1g main area", ImVec2(625.f, 580.f));
			{
				ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.14f, 0.14f, 0.14f, 1.f));
				ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.17f, 0.17f, 0.17f, 1.f));
				ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.17f, 0.17f, 0.17f, 1.f));
				ImGui::PushStyleColor(ImGuiCol_ChildWindowBg, ImVec4(0.07f, 0.07f, 0.07f, 1.f));
				ImGui::PushFont(fDefault);
				if (tabselected == 0)
				{
					ImGui::BeginChild("##more ragebot stuff", ImVec2(310.f, 288.f));
					{
						//more ragebot settings
						ImGui::Checkbox(XorStr(u8"激活"), &g_Options.Ragebot.MainSwitch);
						ImGui::Spacing();
						ImGui::Separator();
						ImGui::Checkbox(XorStr(u8"启用"), &g_Options.Ragebot.Enabled);
						ImGui::SliderFloat(XorStr("FOV"), &g_Options.Ragebot.FOV, 1.f, 180.f, "%.0f");
						ImGui::Checkbox(XorStr(u8"静默瞄准"), &g_Options.Ragebot.Silent);
						ImGui::Checkbox(XorStr(u8"自动手枪"), &g_Options.Ragebot.AutoPistol);
						ImGui::Checkbox(XorStr(u8"无后座"), &g_Options.Ragebot.AntiRecoil);

						ImGui::Checkbox(XorStr(u8"自动急停"), &g_Options.Ragebot.AutoStop);
						ImGui::Hotkey(XorStr("##autostop key"), &g_Options.Ragebot.autostopkey);

						ImGui::Checkbox(XorStr(u8"自动蹲下"), &g_Options.Ragebot.AutoCrouch);
						ImGui::Checkbox(XorStr(u8"自动范围"), &g_Options.Ragebot.AutoScope);


						ImGui::Checkbox(XorStr(u8"反自瞄启用"), &g_Options.Ragebot.EnabledAntiAim);



						ImGui::Checkbox(XorStr(u8"自动开火"), &g_Options.Ragebot.AutoFire);
					}
					ImGui::EndChild();

					ImGui::SameLine();

					ImGui::BeginChild("##aimbot stuff", ImVec2(310.f, 288.f));
					{
						// ragebot misc settings
						ImGui::Text(u8"最小伤害");
						ImGui::PushItemWidth(280.f);
						ImGui::SliderFloat(("Snipers##gay"), &g_Options.Ragebot.MinimumDamageSniper, 1.f, 100.f, "%.2f");
						ImGui::SliderFloat(("Rifles##gay"), &g_Options.Ragebot.MinimumDamageRifle, 1.f, 100.f, "%.2f");
						ImGui::SliderFloat(("Pistols##gay"), &g_Options.Ragebot.MinimumDamagePistol, 1.f, 100.f, "%.2f");
						ImGui::SliderFloat(("Heavies##gay"), &g_Options.Ragebot.MinimumDamageHeavy, 1.f, 100.f, "%.2f");
						ImGui::SliderFloat(("SMGs##gay"), &g_Options.Ragebot.MinimumDamageSmg, 1.f, 100.f, "%.2f");
						ImGui::SliderFloat(("Revolver/Deag##gay"), &g_Options.Ragebot.MinimumDamageRevolver, 1.f, 100.f, "%.2f");

						ImGui::Checkbox(XorStr(u8"命中率"), &g_Options.Ragebot.Hitchance);
						ImGui::SliderFloat(XorStr(u8"狙击"), &g_Options.Ragebot.HitchanceSniper, 0.f, 100.f, "%.1f");
						ImGui::SliderFloat(XorStr(u8"步枪"), &g_Options.Ragebot.HitchanceRifle, 0.f, 100.f, "%.1f");
						ImGui::SliderFloat(XorStr(u8"手枪"), &g_Options.Ragebot.HitchancePistol, 0.f, 100.f, "%.1f");
						ImGui::SliderFloat(XorStr(u8"冲锋枪"), &g_Options.Ragebot.HitchanceSmgs, 0.f, 100.f, "%.1f");
						ImGui::SliderFloat(XorStr(u8"重武器"), &g_Options.Ragebot.HitchanceHeavy, 0.f, 100.f, "%.1f");
						ImGui::SliderFloat(XorStr(u8"左轮 / 沙鹰"), &g_Options.Ragebot.HitchanceRevolver, 0.f, 100.f, "%.1f");
					}
					ImGui::EndChild();


					ImGui::BeginChild("##ragebot shit.", ImVec2(310.f, 288.f));
					{
						ImGui::PushItemWidth(184);
						ImGui::Checkbox(XorStr(u8"解析器"), &g_Options.Ragebot.Resolver);
						ImGui::Text(XorStr(u8"拆解之后X轴子弹:"));
						ImGui::SliderFloat(XorStr(u8"射击: "), &g_Options.Ragebot.bruteAfterX, 0, 10, "%1.f");

						ImGui::Separator();
						
						ImGui::Checkbox(XorStr(u8"暴力回溯"), &g_Options.Ragebot.PosAdjust);
						ImGui::Checkbox(XorStr(u8"假延迟补偿"), &g_Options.Ragebot.FakeLagFix);

						ImGui::Separator();

						ImGui::Checkbox(XorStr(u8"边缘"), &g_Options.Ragebot.Edge);
						ImGui::Checkbox(XorStr(u8"反自瞄刀"), &g_Options.Ragebot.KnifeAA);

						ImGui::Separator();

						ImGui::Checkbox(XorStr(u8"启用假延迟"), &g_Options.Ragebot.FakeLag);
						ImGui::SliderInt(XorStr(u8"数量"), &g_Options.Ragebot.FakeLagAmt, 0, 15, "%1.f");

						ImGui::Separator();

						ImGui::Text(XorStr(u8"暴力键"));
						ImGui::SameLine();
						ImGui::Hotkey(XorStr("##gay 1"), &g_Options.Ragebot.KeyPress);
						ImGui::Text(XorStr("BAIM 键 ;)  "));
						ImGui::SameLine();
						ImGui::Hotkey(XorStr("##biggest gay"), &g_Options.Ragebot.BAIMkey);
						ImGui::Hotkey(XorStr("##dawjbdkajwbwd"), &g_Options.Ragebot.flipkey);

						
					}
					ImGui::EndChild();

					ImGui::SameLine();

					ImGui::BeginChild("##aa's", ImVec2(310.f, 288.f));
					{
						static int movementtype = 0;
						
						if (ImGui::Button(u8"跑", ImVec2(55, 25)))
							movementtype = 0;
						ImGui::SameLine();
						if (ImGui::Button(u8"走", ImVec2(55, 25)))
							movementtype = 1;
						ImGui::SameLine();
						if (ImGui::Button(u8"站", ImVec2(55, 25)))
							movementtype = 2;
						ImGui::SameLine();
						if (ImGui::Button(u8"假", ImVec2(55, 25)))
							movementtype = 3;
						ImGui::SameLine();
						if (ImGui::Button(u8"蹲", ImVec2(55, 25)))
							movementtype = 4;



						//more is placeholder idk what different movements there r i dont hvh at all. if there are no more than what i lsited just resize the buttons to all fit into 300 evenly so 75 (ImGui::Button("Run", ImVec2(75, 25)))
						//also do all ur aa stuff inside of each of these.
						static int aatabtype = 0;
						static int aatabtype1 = 0;
						static int aatabtype2 = 0;
						static int aatabtype3 = 0;
						static int aatabtype4 = 0;

						switch (movementtype)
						
						case 0:
						{
							ImGui::Checkbox(XorStr("AA On Run"), &g_Options.Ragebot.AA_onRun);

							
							if (ImGui::Button("Presets", ImVec2(150, 25))) aatabtype = 0;
							ImGui::SameLine();
							if (ImGui::Button(u8"自身模式", ImVec2(150, 25))) aatabtype = 1;

							if (aatabtype == 0) //run_
							{
								ImGui::Checkbox(XorStr(u8"启用"), &g_Options.Ragebot.run_PreAAs);
								ImGui::SameLine();
								ImGui::Checkbox(u8"假头", &g_Options.Ragebot.run_fakehead);
								ImGui::Combo(XorStr(u8"补偿"), &g_Options.Ragebot.run_Pitch, antiaimpitch, ARRAYSIZE(antiaimpitch));
								ImGui::SliderFloat(XorStr(u8"补偿加法器: "), &g_Options.Ragebot.run_PitchAdder, -180, 180, "%1.f");
								ImGui::Separator();
								ImGui::Combo(XorStr(u8"偏航"), &g_Options.Ragebot.run_YawTrue, antiaimyawtrue, ARRAYSIZE(antiaimyawtrue));
								ImGui::SliderFloat(XorStr(u8"真实加法器: "), &g_Options.Ragebot.run_YawTrueAdder, -180, 180, "%1.f");
								ImGui::Separator();
								ImGui::Combo(XorStr(u8"假偏航"), &g_Options.Ragebot.run_YawFake, antiaimyawfake, ARRAYSIZE(antiaimyawfake));
								ImGui::SliderFloat(XorStr(u8"假加法器: "), &g_Options.Ragebot.run_YawFakeAdder, -180, 180, "%1.f");
							}
							else if (aatabtype == 1)
							{
								ImGui::Checkbox(XorStr(u8"启用"), &g_Options.Ragebot.run_BuilderAAs);
								ImGui::SliderFloat(XorStr("Pitch Angle: "), &g_Options.Ragebot.run_BuilderPitch, -89, 89, "%1.f");
								ImGui::SliderFloat(XorStr("Real Angle: "), &g_Options.Ragebot.run_BuilderReal, -180, 180, "%1.f");
								ImGui::SliderFloat(XorStr("Fake Angle: "), &g_Options.Ragebot.run_BuilderFake, -180, 180, "%1.f");
								ImGui::Checkbox(XorStr("Enable Real Jitter"), &g_Options.Ragebot.run_Jitter);
								ImGui::SliderFloat(XorStr("Jitter Range: "), &g_Options.Ragebot.run_JitterRange, -90, 90, "%1.f");
								ImGui::Checkbox(XorStr("Enable Fake Jitter"), &g_Options.Ragebot.run_FJitter);
								ImGui::SliderFloat(XorStr("FJitter Range: "), &g_Options.Ragebot.run_FJitterRange, -90, 90, "%1.f");
								ImGui::Checkbox(XorStr("LBY Breaker"), &g_Options.Ragebot.run_LBYBreaker);
							}
							break;
						case 1:
							ImGui::Checkbox(XorStr("AA On Walk"), &g_Options.Ragebot.AA_onWalk);

							
							if (ImGui::Button("Presets", ImVec2(150, 25))) aatabtype1 = 0;
							ImGui::SameLine();
							if (ImGui::Button("Self Made", ImVec2(150, 25))) aatabtype1 = 1;

							if (aatabtype1 == 0) //walk_
							{
								ImGui::Checkbox(XorStr("Enable"), &g_Options.Ragebot.walk_PreAAs);
								ImGui::SameLine();
								ImGui::Checkbox("fakehead", &g_Options.Ragebot.walk_fakehead);
								ImGui::Combo(XorStr("Pitch"), &g_Options.Ragebot.walk_Pitch, antiaimpitch, ARRAYSIZE(antiaimpitch));
								ImGui::SliderFloat(XorStr("Pitch Adder: "), &g_Options.Ragebot.walk_PitchAdder, -180, 180, "%1.f");
								ImGui::Separator();
								ImGui::Combo(XorStr("Yaw"), &g_Options.Ragebot.walk_YawTrue, antiaimyawtrue, ARRAYSIZE(antiaimyawtrue));
								ImGui::SliderFloat(XorStr("Real Adder: "), &g_Options.Ragebot.walk_YawTrueAdder, -180, 180, "%1.f");
								ImGui::Separator();
								ImGui::Combo(XorStr("Fake-Yaw"), &g_Options.Ragebot.walk_YawFake, antiaimyawfake, ARRAYSIZE(antiaimyawfake));
								ImGui::SliderFloat(XorStr("Fake Adder: "), &g_Options.Ragebot.walk_YawFakeAdder, -180, 180, "%1.f");
							}
							else if (aatabtype1 == 1)
							{
								ImGui::Checkbox(XorStr("Enable"), &g_Options.Ragebot.walk_BuilderAAs);
								ImGui::SliderFloat(XorStr("Pitch Angle: "), &g_Options.Ragebot.walk_BuilderPitch, -89, 89, "%1.f");
								ImGui::SliderFloat(XorStr("Real Angle: "), &g_Options.Ragebot.walk_BuilderReal, -180, 180, "%1.f");
								ImGui::SliderFloat(XorStr("Fake Angle: "), &g_Options.Ragebot.walk_BuilderFake, -180, 180, "%1.f");
								ImGui::Checkbox(XorStr("Enable Real Jitter"), &g_Options.Ragebot.walk_Jitter);
								ImGui::SliderFloat(XorStr("Jitter Range: "), &g_Options.Ragebot.walk_JitterRange, -90, 90, "%1.f");
								ImGui::Checkbox(XorStr("Enable Fake Jitter"), &g_Options.Ragebot.walk_FJitter);
								ImGui::SliderFloat(XorStr("FJitter Range: "), &g_Options.Ragebot.walk_FJitterRange, -90, 90, "%1.f");
								ImGui::Checkbox(XorStr("LBY Breaker"), &g_Options.Ragebot.walk_LBYBreaker);
							}
							break;
						case 2:
							ImGui::Checkbox(XorStr("AA On Stand"), &g_Options.Ragebot.AA_onStand);
							

							
							if (ImGui::Button("Presets", ImVec2(150, 25))) aatabtype2 = 0;
							ImGui::SameLine();
							if (ImGui::Button("Self Made", ImVec2(150, 25))) aatabtype2 = 1;

							if (aatabtype2 == 0) //stand_
							{
								ImGui::Checkbox(XorStr(u8"启用"), &g_Options.Ragebot.stand_PreAAs);
								ImGui::SameLine();
								ImGui::Checkbox(u8"假头", &g_Options.Ragebot.stand_fakehead);
								ImGui::Combo(XorStr("Pitch"), &g_Options.Ragebot.stand_Pitch, antiaimpitch, ARRAYSIZE(antiaimpitch));
								ImGui::SliderFloat(XorStr("Pitch Adder: "), &g_Options.Ragebot.stand_PitchAdder, -180, 180, "%1.f");
								ImGui::Separator();
								ImGui::Combo(XorStr("Yaw"), &g_Options.Ragebot.stand_YawTrue, antiaimyawtrue, ARRAYSIZE(antiaimyawtrue));
								ImGui::SliderFloat(XorStr("Real Adder: "), &g_Options.Ragebot.stand_YawTrueAdder, -180, 180, "%1.f");
								ImGui::Separator();
								ImGui::Combo(XorStr("Fake-Yaw"), &g_Options.Ragebot.stand_YawFake, antiaimyawfake, ARRAYSIZE(antiaimyawfake));
								ImGui::SliderFloat(XorStr("Fake Adder: "), &g_Options.Ragebot.stand_YawFakeAdder, -180, 180, "%1.f");
								
							}
							else if (aatabtype2 == 1)
							{

								ImGui::Checkbox(XorStr("启用"), &g_Options.Ragebot.stand_BuilderAAs);
								ImGui::SliderFloat(XorStr("Pitch Angle: "), &g_Options.Ragebot.stand_BuilderPitch, -89, 89, "%1.f");
								ImGui::SliderFloat(XorStr("Real Angle: "), &g_Options.Ragebot.stand_BuilderReal, -180, 180, "%1.f");
								ImGui::SliderFloat(XorStr("Fake Angle: "), &g_Options.Ragebot.stand_BuilderFake, -180, 180, "%1.f");
								ImGui::Checkbox(XorStr("Enable Real Jitter"), &g_Options.Ragebot.stand_Jitter);
								ImGui::SliderFloat(XorStr("Jitter Range: "), &g_Options.Ragebot.stand_JitterRange, -90, 90, "%1.f");
								ImGui::Checkbox(XorStr("Enable Fake Jitter"), &g_Options.Ragebot.stand_FJitter);
								ImGui::SliderFloat(XorStr("FJitter Range: "), &g_Options.Ragebot.stand_FJitterRange, -90, 90, "%1.f");
								ImGui::Checkbox(XorStr("LBY Breaker"), &g_Options.Ragebot.stand_LBYBreaker);
							}
							break;
						case 3:
							ImGui::Checkbox(XorStr("AA On FakeWalk"), &g_Options.Ragebot.AA_onFakeWalk);
							

							
							if (ImGui::Button("Presets", ImVec2(150, 25))) aatabtype3 = 0;
							ImGui::SameLine();
							if (ImGui::Button("Self Made", ImVec2(150, 25))) aatabtype3 = 1;

							if (aatabtype3 == 0) //fwalk_
							{
								ImGui::Checkbox(XorStr("启用"), &g_Options.Ragebot.fwalk_PreAAs);
								ImGui::SameLine();
								ImGui::Checkbox("假头", &g_Options.Ragebot.fwalk_fakehead);
								ImGui::Combo(XorStr("Pitch"), &g_Options.Ragebot.fwalk_Pitch, antiaimpitch, ARRAYSIZE(antiaimpitch));
								ImGui::SliderFloat(XorStr("Pitch Adder: "), &g_Options.Ragebot.fwalk_PitchAdder, -180, 180, "%1.f");
								ImGui::Separator();
								ImGui::Combo(XorStr("Yaw"), &g_Options.Ragebot.fwalk_YawTrue, antiaimyawtrue, ARRAYSIZE(antiaimyawtrue));						
								ImGui::SliderFloat(XorStr("Real Adder: "), &g_Options.Ragebot.fwalk_YawTrueAdder, -180, 180, "%1.f");
								ImGui::Separator();
								ImGui::Combo(XorStr("Fake-Yaw"), &g_Options.Ragebot.fwalk_YawFake, antiaimyawfake, ARRAYSIZE(antiaimyawfake));
								ImGui::SliderFloat(XorStr("Fake Adder: "), &g_Options.Ragebot.fwalk_YawFakeAdder, -180, 180, "%1.f");
							}
							else if (aatabtype3 == 1)
							{
								ImGui::Checkbox(XorStr("启用"), &g_Options.Ragebot.fwalk_BuilderAAs);
								ImGui::SliderFloat(XorStr("Pitch Angle: "), &g_Options.Ragebot.fwalk_BuilderPitch, -89, 89, "%1.f");
								ImGui::SliderFloat(XorStr("Real Angle: "), &g_Options.Ragebot.fwalk_BuilderReal, -180, 180, "%1.f");
								ImGui::SliderFloat(XorStr("Fake Angle: "), &g_Options.Ragebot.fwalk_BuilderFake, -180, 180, "%1.f");
								ImGui::Checkbox(XorStr("Enable Real Jitter"), &g_Options.Ragebot.fwalk_Jitter);
								ImGui::SliderFloat(XorStr("Jitter Range: "), &g_Options.Ragebot.fwalk_JitterRange, -90, 90, "%1.f");
								ImGui::Checkbox(XorStr("Enable Fake Jitter"), &g_Options.Ragebot.fwalk_FJitter);
								ImGui::SliderFloat(XorStr("FJitter Range: "), &g_Options.Ragebot.fwalk_FJitterRange, -90, 90, "%1.f");
								ImGui::Checkbox(XorStr("LBY Breaker"), &g_Options.Ragebot.fwalk_LBYBreaker);
							}
							break;
						case 4:
							ImGui::Checkbox(XorStr(u8"AA 蹲伏"), &g_Options.Ragebot.AA_onCrouch);
							

							
							if (ImGui::Button(u8"预置", ImVec2(150, 25))) aatabtype4 = 0;
							ImGui::SameLine();
							if (ImGui::Button(u8"自身模式", ImVec2(150, 25))) aatabtype4 = 1;

							if (aatabtype4 == 0) //crouch_
							{
								ImGui::Checkbox(XorStr(u8"启用"), &g_Options.Ragebot.crouch_PreAAs);
								ImGui::SameLine();
								ImGui::Checkbox("fakehead", &g_Options.Ragebot.crouch_fakehead);
								ImGui::Combo(XorStr("Pitch"), &g_Options.Ragebot.crouch_Pitch, antiaimpitch, ARRAYSIZE(antiaimpitch));
								ImGui::SliderFloat(XorStr("Pitch Adder: "), &g_Options.Ragebot.crouch_PitchAdder, -180, 180, "%1.f");
								ImGui::Separator();
								ImGui::Combo(XorStr("Yaw"), &g_Options.Ragebot.crouch_YawTrue, antiaimyawtrue, ARRAYSIZE(antiaimyawtrue));
								ImGui::SliderFloat(XorStr("Real Adder: "), &g_Options.Ragebot.crouch_YawTrueAdder, -180, 180, "%1.f");
								ImGui::Separator();
								ImGui::Combo(XorStr("Fake-Yaw"), &g_Options.Ragebot.crouch_YawFake, antiaimyawfake, ARRAYSIZE(antiaimyawfake));
								ImGui::SliderFloat(XorStr("Fake Adder: "), &g_Options.Ragebot.crouch_YawFakeAdder, -180, 180, "%1.f");
							}
							else if (aatabtype4 == 1)
							{
								ImGui::Checkbox(XorStr(u8"启用"), &g_Options.Ragebot.crouch_BuilderAAs);
								ImGui::SliderFloat(XorStr("Pitch Angle: "), &g_Options.Ragebot.crouch_BuilderPitch, -89, 89, "%1.f");
								ImGui::SliderFloat(XorStr("Real Angle: "), &g_Options.Ragebot.crouch_BuilderReal, -180, 180, "%1.f");
								ImGui::SliderFloat(XorStr("Fake Angle: "), &g_Options.Ragebot.crouch_BuilderFake, -180, 180, "%1.f");
								ImGui::Checkbox(XorStr("Enable Real Jitter"), &g_Options.Ragebot.crouch_Jitter);
								ImGui::SliderFloat(XorStr("Jitter Range: "), &g_Options.Ragebot.crouch_JitterRange, -90, 90, "%1.f");
								ImGui::Checkbox(XorStr("Enable Fake Jitter"), &g_Options.Ragebot.crouch_FJitter);
								ImGui::SliderFloat(XorStr("FJitter Range: "), &g_Options.Ragebot.crouch_FJitterRange, -90, 90, "%1.f");
								ImGui::Checkbox(XorStr("LBY Breaker"), &g_Options.Ragebot.crouch_LBYBreaker);
							}
							break;
						}

					}
					ImGui::EndChild();


				}
				else if (tabselected == 1)
				{





					static int legitguntab = 0;
					ImGui::PushFont(guns);
					if (ImGui::Button("a", ImVec2(120, 80))) legitguntab = 0;
					ImGui::SameLine();
					if (ImGui::Button("S", ImVec2(120, 80))) legitguntab = 1;
					ImGui::SameLine();
					if (ImGui::Button("G", ImVec2(120, 80))) legitguntab = 2;


					ImGui::PushFont(fDefault);
					ImGui::BeginChild("##big shit here", ImVec2(625.f, 250.f));
					{
						switch (legitguntab)
						{
						case 0:
							ImGui::Text(u8"狙击");
							ImGui::PushItemWidth(184);
							ImGui::Hotkey(XorStr("Key##2"), &g_Options.Legitbot.SniperKey);
							ImGui::SliderFloat(XorStr(u8"光滑##2"), &g_Options.Legitbot.SniperSmooth, 1.00f, 100.00f, "%.2f");
							ImGui::SliderFloat(XorStr(u8"FOV##2"), &g_Options.Legitbot.Sniperfov, 0.00f, 30.00f, "%.2f");
							ImGui::SliderFloat(XorStr(u8"最小压枪##2"), &g_Options.Legitbot.sniper_recoil_min, 1.00f, 100.00f, "%.2f");
							ImGui::SliderFloat(XorStr(u8"最大压枪##2"), &g_Options.Legitbot.sniper_recoil_max, 1.00f, 100.00f, "%.2f");
							break;
						case 1:
							ImGui::Text(u8"步枪");
							ImGui::PushItemWidth(184);
							ImGui::Hotkey(XorStr("Key##0"), &g_Options.Legitbot.MainKey);
							ImGui::SliderFloat(XorStr(u8"光滑##0"), &g_Options.Legitbot.MainSmooth, 1.00f, 100.00f, "%.2f");
							ImGui::SliderFloat(XorStr(u8"FOV##0"), &g_Options.Legitbot.Mainfov, 0.00f, 30.00f, "%.2f");
							ImGui::SliderFloat(XorStr(u8"最小压枪##0"), &g_Options.Legitbot.main_recoil_min, 1.00f, 100.00f, "%.2f");
							ImGui::SliderFloat(XorStr(u8"最大压枪##0"), &g_Options.Legitbot.main_recoil_max, 1.00f, 100.00f, "%.2f");
							ImGui::Separator();
							ImGui::Checkbox(XorStr(u8"合法回溯"), &g_Options.Legitbot.backtrack);
							ImGui::SliderFloat(XorStr("Ticks: "), &g_Options.Legitbot.backtrackTicks, 0, 12, "%1.f");
							break;
						case 2:
							ImGui::Text(u8"手枪");
							ImGui::PushItemWidth(184);
							ImGui::Hotkey(XorStr("Key##1"), &g_Options.Legitbot.PistolKey);
							ImGui::SliderFloat(XorStr(u8"光滑##1"), &g_Options.Legitbot.PistolSmooth, 1.00f, 100.00f, "%.2f");
							ImGui::SliderFloat(XorStr(u8"FOV##1"), &g_Options.Legitbot.Pistolfov, 0.00f, 30.00f, "%.2f");
							ImGui::SliderFloat(XorStr(u8"最小压枪##1"), &g_Options.Legitbot.pistol_recoil_min, 1.00f, 100.00f, "%.2f");
							ImGui::SliderFloat(XorStr(u8"最大压枪##1"), &g_Options.Legitbot.pistol_recoil_max, 1.00f, 100.00f, "%.2f");
							break;							
						}
					}
					ImGui::EndChild();
					ImGui::BeginChild("##more legitbot stuff", ImVec2(625.f, 200.f));
					{

					}
					ImGui::EndChild();

				}
				else if (tabselected == 2)
				{
					ImGui::BeginChild("##visuals 1", ImVec2(310.f, 580.f));
					{
						ImGui::Text(u8"视觉");
						ImGui::Checkbox(XorStr(u8"队伍 ESP"), &g_Options.Visuals.TeamESP);
						ImGui::SameLine();
						ImGui::MyColorEdit3("##ESP", g_Options.Colors.TeamESP, 1 << 7);
						ImGui::Checkbox(XorStr(u8"盒子"), &g_Options.Visuals.Box);
						ImGui::SameLine();
						ImGui::MyColorEdit3("##EdddSP", g_Options.Colors.EnemyESP, 1 << 7);
						ImGui::Combo("##boxkek", &g_Options.Visuals.BoxType, "Full\0\rCorners\0\r3D\0\0", -1);
						ImGui::Checkbox(XorStr(u8"骨架"), &g_Options.Visuals.Skeleton);
						
						ImGui::Checkbox(XorStr(u8"手榴弹预测"), &g_Options.Visuals.GrenadePrediction);

						ImGui::Spacing();
						ImGui::Separator();
						ImGui::Text(u8"玩家统计.");

						ImGui::Checkbox(XorStr(u8"名字"), &g_Options.Visuals.Name);
						ImGui::Checkbox(XorStr(u8"武器"), &g_Options.Visuals.Weapon);
						ImGui::Combo("##wpnkek", &g_Options.Visuals.wpnmode, "Name\0\rIcon\0\0", -1);
						ImGui::Checkbox(XorStr(u8"盔甲"), &g_Options.Visuals.Armor);
						ImGui::Checkbox(XorStr(u8"生命"), &g_Options.Visuals.health);
						ImGui::Checkbox(XorStr(u8"钱"), &g_Options.Visuals.Money);
						ImGui::Checkbox(XorStr("Callout"), &g_Options.Visuals.Callout);


						ImGui::Checkbox(XorStr(u8"敌人状态"), &g_Options.Visuals.Flashed);
						ImGui::Checkbox(XorStr(u8"距离"), &g_Options.Visuals.Distance);

						ImGui::Spacing();
						ImGui::Spacing();
						ImGui::Separator();
						ImGui::Spacing();

						ImGui::Checkbox(XorStr(u8"瞄准线"), &g_Options.Visuals.AimLine);
						ImGui::Checkbox(XorStr(u8"角度线"), &g_Options.Visuals.angleLines);
						ImGui::Checkbox(XorStr(u8"Awall 指示"), &g_Options.Visuals.DrawAwall);
						ImGui::Checkbox(XorStr(u8"LBY 指示"), &g_Options.Visuals.LBYIndicator);



					}
					ImGui::EndChild();

					ImGui::SameLine();

					ImGui::BeginChild("##visuals 2", ImVec2(310.f, 580.f));
					{
						ImGui::Text(u8"视觉 继续");

						ImGui::Checkbox(XorStr(u8"夜晚模式"), &g_Options.Misc.nightMode);
						ImGui::Checkbox(XorStr(u8"第三人称"), &g_Options.Visuals.ThirdPerson);
						ImGui::Hotkey(XorStr("Key##273"), &g_Options.Visuals.TPKey);
						//ImGui::SliderFloat(XorStr("##tpdist"), &g_Options.Visuals.tpdist, 50.f, 500.f, "%.0f");
						ImGui::Checkbox(XorStr(u8"击中标记"), &g_Options.Visuals.Hitmarker);
						ImGui::Text(XorStr(u8"击中声音:"));
						ImGui::SameLine();
						ImGui::Combo(XorStr("##anullar destruction"), &g_Options.Visuals.Hitsound, HitmarkSound, ARRAYSIZE(HitmarkSound));
						ImGui::Checkbox(XorStr(u8"事件日志 (Beta)"), &g_Options.Visuals.EventLog);

						ImGui::PushItemWidth(184);
						ImGui::SliderFloat(XorStr("FOV"), &g_Options.Visuals.FOVChanger, 0, 60, "%.0f");
						ImGui::SliderFloat(XorStr(u8"视图FOV"), &g_Options.Visuals.viewmodelChanger, 0, 130, "%.0f");
						//ImGui::Checkbox(XorStr("Angle Lines"), &g_Options.Visuals.angleLines);
						ImGui::Checkbox(XorStr(u8"炸弹透视"), &g_Options.Visuals.Bomb);
						ImGui::Checkbox(XorStr(u8"手榴弹"), &g_Options.Visuals.Grenades);
						ImGui::Checkbox(XorStr(u8"解析器模式"), &g_Options.Visuals.resolveMode);
						ImGui::Checkbox(XorStr(u8"掉落的武器"), &g_Options.Visuals.Droppedguns);
						ImGui::Checkbox(XorStr(u8"无烟"), &g_Options.Visuals.NoSmoke);
						ImGui::Checkbox(XorStr(u8"无闪"), &g_Options.Visuals.NoFlash);
						ImGui::Checkbox(XorStr(u8"无范围"), &g_Options.Visuals.noscopeborder);

					}
					ImGui::EndChild();
				}
				else if (tabselected == 3)
				{
					ImGui::BeginChild("##misc options", ImVec2(310.f, 580.f));
					{
						ImGui::Text(u8"杂项:");

						if (ImGui::Button(XorStr(u8"卸载hook")))
						{
							g_Engine->ClientCmd_Unrestricted("cl_mouseenable 1");
							unload = true;
						}
						ImGui::Checkbox(u8"反不可信", &g_Options.Misc.antiuntrusted);
						
						ImGui::Combo(XorStr(u8"组名"), &g_Options.Misc.clantag_SLN, ClanTags, ARRAYSIZE(ClanTags));
						ImGui::Checkbox(u8"Ayyware Crasher", &g_Options.Ragebot.ayywarecrasher);
						ImGui::Checkbox(u8"垃圾名字", &g_Options.Misc.namespam);
						
						ImGui::Checkbox(XorStr(u8"兔子跳"), &g_Options.Misc.Bhop);
						ImGui::Checkbox(XorStr(u8"自动扫射"), &g_Options.Misc.AutoStrafe);

						ImGui::Checkbox(XorStr(u8"太空步"), &g_Options.Misc.moonwalk);
						ImGui::Checkbox(XorStr(u8"幽灵走"), &g_Options.Misc.spookwalk);

						ImGui::Checkbox(XorStr(u8"假走"), &g_Options.Misc.fakewalk);
						ImGui::Hotkey(XorStr(u8"##fakewalk key"), &g_Options.Misc.fakewalkkey);


						ImGui::Text(u8"配置");
						ImGui::Combo((u8"文件"), &g_Options.Menu.ConfigFile, configFiles, ARRAYSIZE(configFiles));
						if (ImGui::Button(u8"保存配置")) Config->Save();

						if (ImGui::Button(u8"载入配置")) Config->Load();

					}
					ImGui::EndChild();

					ImGui::SameLine();

					ImGui::BeginChild("##misc options 2", ImVec2(310.f, 580.f));
					{
						ImGui::Text(u8"杂项 继续:");
						//more visual shit

					}
					ImGui::EndChild();
				}
				else if (tabselected == 4)
				{

				}
				else if (tabselected == 5)
				{

				}
				ImGui::EndChild();
			}


			
		}ImGui::End();
	}
}
