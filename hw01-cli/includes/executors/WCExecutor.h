#ifndef HW01_CLI_WCEXECUTOR_H
#define HW01_CLI_WCEXECUTOR_H

#include <executors/ICommandExecutor.h>
#include <optional>

class WCExecutor : public ICommandExecutor {
public:
    Status execute(
            const Command &command,
            StringChannel &inputStream,
            StringChannel &outputStream
    ) const override;

private:
    class Counter;

    void writeCounterToChannel(
            const Counter &counter,
            StringChannel &outputChannel,
            const std::string &message = ""
    ) const;

    WCExecutor::Counter executeChannelMode(
            const CommandArguments &commandArguments,
            StringChannel &inputChannel,
            StringChannel &outputChannel
    ) const;

    WCExecutor::Counter executeFileMode(const std::string &fileName) const;

    class Counter {
    public:
        void append(char c);

        void append(const std::string s);

        int getNewlinesCount() const;

        int getWordsCount() const;

        int getBytesCount() const;

    private:
        static bool isWordSymbol(char c);

    private:
        int newlinesCount = 0;
        int wordsCount = 0;
        int bytesCount = 0;

        std::optional<char> lastSymbol;
    };
};


#endif //HW01_CLI_WCEXECUTOR_H
