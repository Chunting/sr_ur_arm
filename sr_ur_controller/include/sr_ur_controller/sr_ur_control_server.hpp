/*
 * Copyright (c) 2014, Shadow Robot Company, All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.
 */

/*
 * sr_ur_contol_server.hpp
 *
 *  Created on: 20 Oct 2014
 *      Author: Manos Nikolaidis
 */

#ifndef SR_UR_READ_WRITE_HPP_
#define SR_UR_READ_WRITE_HPP_

#include <uv.h>
#include "sr_ur_controller/sr_ur_driver.hpp"

struct UrControlServer
{
  UrRobotDriver *ur_;

  uv_tcp_t server_stream_;
  uv_tcp_t command_stream_;

  uv_buf_t command_buffer_;
  uv_buf_t response_buffer_;

  uv_write_t write_request_;

  void start();
  void stop();

  void send_command();
  void send_ur_quit();
  void send_ur_stop();
  void send_ur_set_teach_mode(bool teach_mode);
};

#endif