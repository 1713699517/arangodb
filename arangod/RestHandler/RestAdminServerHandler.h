////////////////////////////////////////////////////////////////////////////////
/// DISCLAIMER
///
/// Copyright 2014-2017 ArangoDB GmbH, Cologne, Germany
/// Copyright 2004-2014 triAGENS GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is ArangoDB GmbH, Cologne, Germany
///
/// @author Andreas Streichardt
////////////////////////////////////////////////////////////////////////////////

#ifndef ARANGOD_REST_HANDLER_REST_ADMIN_SERVER_HANDLER_H
#define ARANGOD_REST_HANDLER_REST_ADMIN_SERVER_HANDLER_H 1

#include "Basics/Common.h"
#include "Cluster/ServerState.h"
#include "RestHandler/RestBaseHandler.h"

namespace arangodb {

////////////////////////////////////////////////////////////////////////////////
/// @brief admin log request handler
////////////////////////////////////////////////////////////////////////////////

class RestAdminServerHandler : public RestBaseHandler {
 public:
  explicit RestAdminServerHandler(GeneralRequest*, GeneralResponse*);

 public:
  char const* name() const override final { return "RestAdminServerHandler"; }

  bool isDirect() const override { return true; };
  RestStatus execute() override;

 private:
  void handleMode();
  void handleId();
  void handleRole();
  void handleAvailability();
  void writeModeResult(ServerState::Mode const&);
};
}

#endif