/**
 * @copyright 2022-2022 Uniontech Technology Co., Ltd.
 *
 * @file
 *
 * @brief
 *
 * @date
 *
 * Author: liuwh  <2398819901@qq.com>
 *
 * Maintainer: liuwh  <2398819901@qq.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef TRANSSTRUCT_H
#define TRANSSTRUCT_H
#include <string>

using std::string;


class TransStruct
{
public:
    TransStruct();
    string topic;           //kafka主题
    string protocol;        //协议 mysql http https
    u_short source{};       //源端口
    u_short dest{};         //目的端口
    char saddrIPv4[4]{};    //源ip   ipv4
    char daddrIPv4[4]{};    //目的ip ivp4
    char saddrIPv6[16]{};   //源ip   ipv6
    char daddrIPv6[16]{};   //目的ip ipv6
    char*data{};            //有效载荷 tcp数据
};

#endif // TRANSSTRUCT_H
