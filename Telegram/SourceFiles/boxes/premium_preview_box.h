/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include "base/object_ptr.h"

class DocumentData;

namespace ChatHelpers {
class Show;
} // namespace ChatHelpers

namespace Data {
struct ReactionId;
} // namespace Data

namespace Ui {
class BoxContent;
class GenericBox;
class GradientButton;
} // namespace Ui

namespace Window {
class SessionController;
} // namespace Window

namespace Main {
class Session;
} // namespace Main

void ShowStickerPreviewBox(
	std::shared_ptr<ChatHelpers::Show> show,
	not_null<DocumentData*> document);

void DoubledLimitsPreviewBox(
	not_null<Ui::GenericBox*> box,
	not_null<Main::Session*> session);

enum class PremiumPreview {
	MoreUpload,
	FasterDownload,
	VoiceToText,
	NoAds,
	EmojiStatus,
	InfiniteReactions,
	Stickers,
	AnimatedEmoji,
	AdvancedChatManagement,
	ProfileBadge,
	AnimatedUserpics,
	RealTimeTranslation,

	kCount,
};

void ShowPremiumPreviewBox(
	not_null<Window::SessionController*> controller,
	PremiumPreview section,
	Fn<void(not_null<Ui::BoxContent*>)> shown = nullptr);

void ShowPremiumPreviewBox(
	std::shared_ptr<ChatHelpers::Show> show,
	PremiumPreview section,
	Fn<void(not_null<Ui::BoxContent*>)> shown = nullptr);

void ShowPremiumPreviewToBuy(
	not_null<Window::SessionController*> controller,
	PremiumPreview section,
	Fn<void()> hiddenCallback = nullptr);

void PremiumUnavailableBox(not_null<Ui::GenericBox*> box);

[[nodiscard]] object_ptr<Ui::GradientButton> CreateUnlockButton(
	QWidget *parent,
	rpl::producer<QString> text);
