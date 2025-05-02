// Fill out your copyright notice in the Description page of Project Settings.


#include "Aura/Public/UI/Widget/AuraUserWidget.h"

void UAuraUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
