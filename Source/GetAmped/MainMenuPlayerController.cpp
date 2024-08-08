#include "MainMenuPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"

void AMainMenuPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (WidgetClass != nullptr)
    {
        CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);
        if (CurrentWidget != nullptr)
        {
            CurrentWidget->AddToViewport();
            SetInputModeUIOnly(); // �Է� ��� ���� ȣ��
        }
    }
}

void AMainMenuPlayerController::SetInputModeUIOnly()
{
    if (CurrentWidget)
    {
        FInputModeUIOnly InputMode; // �Է� ��带 UI �������� ����
        InputMode.SetWidgetToFocus(CurrentWidget->TakeWidget()); // ����ڰ� UI�� ��ȣ�ۿ� ����
        SetInputMode(InputMode); // �÷��̾� ��Ʈ�ѷ��� �Է� ��� ����
        bShowMouseCursor = true; // ���콺 Ŀ���� ���̰� ����
    }
}