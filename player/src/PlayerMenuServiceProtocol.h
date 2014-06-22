//
//  PlayerMenuServiceProtocol.h
//  quick-x-player
//

#ifndef __PLAYER_MENU_SERVICE_PROTOCOL_H
#define __PLAYER_MENU_SERVICE_PROTOCOL_H

#include "PlayerMacros.h"
#include "PlayerServiceProtocol.h"

#include <string>

PLAYER_NS_BEGIN

#define MAX_INT ((unsigned)(-1))>>1
#define MIN_INT ~MAX_INT

#define kPlayerSuperModifyKey "super"
#define kPlayerShiftModifyKey "shift"
#define kPlayerCtrlModifyKey  "ctrl"
#define kPlayerAltModifyKey   "alt"


class MenuItem
{
public:
    MenuItem():itemId(""), scriptHandlerId(0),isChecked(false),isEnabled(true), shortcut("")
    {
    }
    
    std::string itemId;     // 该菜单项id
//    int index;              // 该菜单项在同级菜单中的索引（从 0 开始的位置）
    std::string title;      // 菜单名称
    bool isGroup;           // 是否是菜单组
    bool isEnabled;         // 是否可以点击
    bool isChecked;         // 是否设置为已选中状态（如果是菜单组，则忽略该设置）
    std::string shortcut;   // 键盘快捷键（如果是菜单组，则忽略该设置）
    int scriptHandlerId;    // 事件回调的 Lua 脚本 id
};

class PlayerMenuServiceProtocol
{
public:
    // 添加一个菜单项
    //
    // 如果 @parentIndex < = 0不存在, 则添加为顶级菜单
    //
    // @param item 菜单项定义
    // @param parentIndex 父级菜单对象
    virtual void addItem(const MenuItem &item,
                         std::string parentId = std::string(),
                         int index = MAX_INT) = 0;
    
    
    // 修改一个菜单项
    //
    // @param item 菜单项
    virtual void modifyItem(const MenuItem &item) = 0;
    
    
    // 删除一个菜单项
    //
    // @param item 菜单项
    virtual void deleteItem(const MenuItem &item) = 0;
    
};

PLAYER_NS_END

#endif // __PLAYER_MENU_SERVICE_PROTOCOL_H