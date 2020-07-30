#ifndef CHAT_MESSAGE_H
#define CHAT_MESSAGE_H
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include "struct_header.h"

enum {headerLength=sizeof(Header)};
enum {maxBodyLength=512};

class ChatMessage
{
private:
    char mData[headerLength+maxBodyLength];
    Header mHeader;
public:
    ChatMessage()
    {
    }
    const char* getData() const
    {
        return mData;
    }
    char* getData()
    {
        return mData;
    }
    size_t getDataLength() const
    {
        return headerLength + mHeader.bodySize;
    }
    const char* getBody() const
    {
        return mData + headerLength;
    }
    char* getBody()
    {
        return mData + headerLength;    //从数据包指针地址开始位置往后增加一个头长度就是body起始地址位置
    }
    int getType() const
    {
        return mHeader.type;
    }
    size_t getBodyLength() const
    {
        return mHeader.bodySize;
    }
    void setMessage(int messageType, const void* buffer, size_t bufferSize)
    {
        assert(bufferSize <= maxBodyLength);
        mHeader.type = messageType;
        mHeader.bodySize = bufferSize;
        memcpy(getData(), &mHeader, sizeof(mHeader));
        memcpy(getBody(), buffer, bufferSize);
    }
    void setMessage(int messageType, const string& buffer)
    {
        setMessage(messageType, buffer.data(), buffer.size());
    }
    bool decodeHeader()
    {
        memcpy(&mHeader, getData(), headerLength);
        if (mHeader.bodySize > maxBodyLength)
        {
            std::cout << "body size " << mHeader.bodySize << " " << mHeader.type << std::endl;
            return false;
        }
        return true;
    }
};

#endif // CHAT_MESSAGE_H
