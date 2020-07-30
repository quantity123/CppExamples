#ifndef STRUCT_HEADER_H
#define STRUCT_HEADER_H

#include <cstring>
#include <string>
#include "json_object.h"
#include "Protocal.pb.h"

using namespace std;

struct Header
{
    int bodySize;
    int type;   //body数据类型，比如BindName=0，ChatInformation=1，RoomInformation=2
};

enum MessageType
{
    MT_BINDNAME=1,  //json {"name" : "abc"}
    MT_CHATINFO=2,  //json {"information" : "what i say"}
    MT_ROOMINFO=3,  //json {"name" : "abc", "information" : "what i say"}
};

//client send
struct BindName
{
    char name[32];
    int nameLen;
};

//client send
struct ChatInformation
{
    char information[256];
    int infoLen;
};

//server send
struct RoomInformation
{
    BindName name;
    ChatInformation chat;
};

inline bool parseMessage(const std::string& input, int* type, std::string& outBuffer)
{
    auto pos = input.find_first_of(" ");    //返回字符串中第一个 空格 的位置
    if (pos == string::npos)    //npos表示没找到
        return false;
    if (pos == 0)
        return false;
    auto command = input.substr(0, pos);    //取出从0位置到pos位置之间的字符赋值给command
    if (command == "BindName")
    {
        string name = input.substr(pos + 1);    //取出pos+1位置到结尾之间的字符
        if (name.size() > 32)
            return false;
        if (type)   //判断类型指针是否为空
            *type = MT_BINDNAME;
        BindName bindInfo;
        bindInfo.nameLen = name.size();
        memcpy(&bindInfo.name, name.data(), name.size());
        auto buffer = reinterpret_cast<const char*>(&bindInfo);
        outBuffer.assign(buffer, buffer+sizeof(bindInfo));
        return true;
    }
    else if (command == "Chat")
    {
        string chat = input.substr(pos + 1);    //取出pos+1位置到结尾之间的字符
        if (chat.size() > 256)
            return false;
        if (type)   //判断类型指针是否为空
            *type = MT_CHATINFO;
        ChatInformation chatInfo;
        memcpy(&chatInfo.information, chat.data(), chat.size());
        chatInfo.infoLen = chat.size();
        auto buffer = reinterpret_cast<const char*>(&chatInfo);
        outBuffer.assign(buffer, buffer+sizeof(chatInfo));
        return true;
    }
    return false;
}

inline bool parseJsonMessage(const std::string& input, int* type, std::string& outBuffer)
{
    auto pos = input.find_first_of(" ");    //返回字符串中第一个 空格 的位置
    if (pos == string::npos)    //npos表示没找到
        return false;
    if (pos == 0)
        return false;
    auto command = input.substr(0, pos);    //取出从0位置到pos位置之间的字符赋值给command
    if (command == "BindName")
    {
        string name = input.substr(pos + 1);    //取出pos+1位置到结尾之间的字符
        if (name.size() > 32)
            return false;
        if (type)   //判断类型指针是否为空
            *type = MT_BINDNAME;
        ptree tree;
        tree.put("name", name);
        outBuffer = ptreeToJsonString(tree);
        return true;
    }
    else if (command == "Chat")
    {
        string chat = input.substr(pos+1);
        if (chat.size() > 256)
            return false;
        if (type)   //判断类型指针是否为空
            *type = MT_CHATINFO;
        ptree tree;
        tree.put("information", chat);
        outBuffer = ptreeToJsonString(tree);
        return true;
    }
    return false;
}

inline bool parseProtoBufMessage(const std::string& input, int* type, std::string& outBuffer)
{
    auto pos = input.find_first_of(" ");    //返回字符串中第一个 空格 的位置
    if (pos == string::npos)    //npos表示没找到
        return false;
    if (pos == 0)
        return false;
    auto command = input.substr(0, pos);    //取出从0位置到pos位置之间的字符赋值给command
    if (command == "BindName")
    {
        string name = input.substr(pos + 1);    //取出pos+1位置到结尾之间的字符
        if (name.size() > 32)
            return false;
        if (type)   //判断类型指针是否为空
            *type = MT_BINDNAME;
        PBindName bindName;
        bindName.set_name(name);
        auto ok = bindName.SerializeToString(&outBuffer);   //把PBindName里字段串行序列化到outBuffer
        return ok;
    }
    else if (command == "Chat")
    {
        string chat = input.substr(pos+1);
        if (chat.size() > 256)
            return false;
        if (type)   //判断类型指针是否为空
            *type = MT_CHATINFO;
        PChat pchat;
        pchat.set_information(chat);
        auto ok = pchat.SerializeToString(&outBuffer);
        return ok;
    }
    return false;
}

#endif // STRUCT_HEADER_H
