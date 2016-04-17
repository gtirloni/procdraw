#include "console.h"

namespace procdraw {

    void Console::Draw()
    {
        int linespace = renderer_->GetLinespace();

        // TODO: Don't need to calculate the cursor pos each time, only when changes
        int cursorX, cursorWidth, cursorHeight;
        renderer_->CalculateBlockCursorPos(inputLine_.GetCursorPos(), &cursorX, &cursorWidth, &cursorHeight);

        int cursorY = linespace * lines_.size();

        int y = 0;

        // Console background
        renderer_->Begin2D();
        renderer_->Color(0, 0, 0, 0.6f);
        renderer_->Rect(0, 0, renderer_->Width(), renderer_->Height());

        // Block cursor background
        renderer_->DrawBlockCursorBackground(cursorX, cursorY, cursorWidth, cursorHeight);

        // Draw text
        renderer_->BeginText();
        for (auto line : lines_) {
            renderer_->DrawText(0, y, line.layout.GetLineVertices(0));
            y += linespace;
        }
        if (inputLineNeedsLayout_) {
            inputLineLayout_ = renderer_->LayOutText(inputLine_.GetLine());
            inputLineNeedsLayout_ = false;
        }
        renderer_->DrawText(0, y, inputLineLayout_.GetLineVertices(0));

        // Do block cursor inversion
        renderer_->Begin2D();
        renderer_->DrawBlockCursorInversion(cursorX, cursorY, cursorWidth, cursorHeight);

        renderer_->Begin3D();
    }

    void Console::InputText(char *text)
    {
        inputLine_.Insert(text[0]);
        inputLineNeedsLayout_ = true;
    }

    void Console::Println(const std::string &str)
    {
        ConsoleLine line(str);
        line.layout = renderer_->LayOutText(str);
        lines_.push_back(line);
    }

    void Console::ProcessKey(SDL_KeyboardEvent *key)
    {
        switch (key->keysym.sym) {
        case SDLK_BACKSPACE:
            inputLine_.DeleteBack();
            inputLineNeedsLayout_ = true;
            break;
        case SDLK_LEFT:
            inputLine_.BackwardChar();
            inputLineNeedsLayout_ = true;
            break;
        case SDLK_RIGHT:
            inputLine_.ForwardChar();
            inputLineNeedsLayout_ = true;
            break;
        case SDLK_RETURN:
            Println(inputLine_.GetLine());
            ProcessReturn();
            inputLine_.Clear(continuedLine_ ? continuedLinePrompt_ : topLevelPrompt_);
            inputLineNeedsLayout_ = true;
            break;
        }
    }

    void Console::ProcessReturn()
    {
        cmd_ += "\n";
        cmd_ += inputLine_.GetUserText();
        switch (cmdProcessor_->CheckCommand(cmd_)) {
        case BalancedState::Balanced:
            Println(cmdProcessor_->DoCommand(cmd_));
            cmd_ = "";
            continuedLine_ = false;
            break;
        case BalancedState::TooManyClosingParens:
            Println("Too many closing parens");
            cmd_ = "";
            continuedLine_ = false;
            break;
        case BalancedState::NotClosed:
            continuedLine_ = true;
            break;
        }
    }

}