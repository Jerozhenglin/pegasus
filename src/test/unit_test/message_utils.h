// Copyright (c) 2017, Xiaomi, Inc.  All rights reserved.
// This source code is licensed under the Apache License Version 2.0, which
// can be found in the LICENSE file in the root directory of this source tree.

#pragma once

#include "rrdb/rrdb_types.h"
#include "rrdb/rrdb.code.definition.h"

#include <dsn/utility/message_utils.h>

namespace pegasus {

inline dsn_message_t create_multi_put_request(const dsn::apps::multi_put_request &request)
{
    return dsn::from_thrift_request_to_received_message(request,
                                                        dsn::apps::RPC_RRDB_RRDB_MULTI_PUT);
}

inline dsn_message_t create_multi_remove_request(const dsn::apps::multi_remove_request &request)
{
    return dsn::from_thrift_request_to_received_message(request,
                                                        dsn::apps::RPC_RRDB_RRDB_MULTI_REMOVE);
}

inline dsn_message_t create_put_request(const dsn::apps::update_request &request)
{
    return dsn::from_thrift_request_to_received_message(request, dsn::apps::RPC_RRDB_RRDB_PUT);
}

inline dsn_message_t create_remove_request(const dsn::blob &key)
{
    return dsn_msg_create_received_request(
        dsn::apps::RPC_RRDB_RRDB_REMOVE, DSF_THRIFT_BINARY, (void *)key.data(), key.length());
}

} // namespace pegasus
