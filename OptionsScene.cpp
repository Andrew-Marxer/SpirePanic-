#include "OptionsScene.h"
#include "Game.h"

OptionsScene::OptionsScene(CGame* game) : Scene(game)
{
	controlsListSelected = true;
	selectedControl = 0;
	pending = false;
	// Create the controls list
	for (auto c : controlMap) controlsList.push_back({ c.first, c.second });
}

void OptionsScene::update() {
	if (pending) {
		for (auto key : keyboardKeys) {
			if (m_pKeyboard->TriggerDown(key.first)) {
				// Update the control
				controlMap[controlsList[selectedControl].first] = key.first;
				controlsList[selectedControl].second = key.first;
				// Cease pending
				pending = false;
			}
		}
	}
	else if (controlsListSelected) {
		// Handle the player moving through the list
		if (m_pKeyboard->TriggerDown(controlMap["PLAYER1_UP"])) selectedControl--;
		else if (m_pKeyboard->TriggerDown(controlMap["PLAYER1_DOWN"])) selectedControl++;
		if (selectedControl >= (int)controlsList.size()) selectedControl = 0;
		else if (selectedControl < 0) selectedControl = (int)controlsList.size() - 1;
		// Set to pending if the player wants to change a control
		if (m_pKeyboard->TriggerDown(controlMap["PLAYER1_ACCEPT"])) pending = true;
	}
	if (m_pKeyboard->TriggerDown(controlMap["PLAYER1_BACK"])) {
		game->startScene(new TitleScreenScene(game));
	}
}

void OptionsScene::render() {
	Scene::render();
	m_pRenderer->setFont("font");
	render_controls();
	string prompts = "Use "
		+ keyboardKeys[controlMap["PLAYER1_UP"]] + " and "
		+ keyboardKeys[controlMap["PLAYER1_DOWN"]]
		+ " to select a control.\n"
		+ "Press "
		+ keyboardKeys[controlMap["PLAYER1_ACCEPT"]]
		+ " to modify the selected control.\n"
		+ "Press "
		+ keyboardKeys[controlMap["PLAYER1_BACK"]]
		+ " to exit this menu...\n";
	m_pRenderer->DrawScreenText(prompts.c_str(), { 15,15 }, Colors::LimeGreen);
}

void OptionsScene::render_controls() {
	float keysXOffset = 800.0f;
	// Draw the names of controls
	for (int r = 0; r < controlsList.size(); r++) {
		auto code = controlsList[r].first;
		auto key = controlsList[r].second;
		// Calculate the Y position
		int offset = selectedControl - r;
		float y = 344.0f - (offset * 32);
		// Draw the text for the selected control
		if (r == selectedControl) {
			m_pRenderer->DrawScreenText(code.c_str(),
				{ keysXOffset, y }, Colors::White);
		}
		// Draw the text for all the unselected controls
		else {
			m_pRenderer->DrawScreenText(code.c_str(),
				{ keysXOffset, y }, Colors::LimeGreen);
		}
		if (!pending || r != selectedControl) {
			// Draw the key currently mapped to the control
			m_pRenderer->DrawScreenText(
				("[ " + keyboardKeys[key] + " ]").c_str(),
				{ 1050.0f, y }, Colors::LimeGreen);
		}
		else {
			// Draw pending text
			m_pRenderer->DrawScreenText("[ Press any key ]",
				{ 1050.0f, y }, Colors::Red);
		}
	}
}