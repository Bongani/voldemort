/* -*- C++ -*-; c-basic-offset: 4; indent-tabs-mode: nil */
/*!
 * @file VoldemortNativeRequestFormat.h
 * @brief Interface definition file for VoldemortNativeRequestFormat
 */
/* Copyright (c) 2009 Webroot Software, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */

#ifndef VOLDEMORTNATIVEREQUESTFORMAT_H
#define VOLDEMORTNATIVEREQUESTFORMAT_H

#include "RequestFormat.h"

#include <list>
#include <string>

namespace Voldemort {

/**
 * The client side of the protocol buffers request format.  This uses
 * the protocol buffers API to read/write the protocol buffers-based
 * network API.
 *
 * Note that this doesn't do well as written for larger values since
 * the protocol buffers API ends up adding extra memory copies of the
 * value.
 */
class VoldemortNativeRequestFormat: public RequestFormat
{
public:
    VoldemortNativeRequestFormat();
    virtual ~VoldemortNativeRequestFormat();

    // RequestFormat interface 
    virtual void writeGetRequest(std::ostream* outputStream,
                                 std::string* storeName,
                                 std::string* key,
                                 bool shouldReroute);
    virtual std::list<VersionedValue>* readGetResponse(std::istream* inputStream);
    virtual void writeGetAllRequest(std::ostream* outputStream,
                                    std::string* storeName,
                                    std::list<std::string*>* keys,
                                    bool shouldReroute);
    /* XXX - TODO */
    //virtual void readGetAllResponse(std::istream* inputStream);
    virtual void writePutRequest(std::ostream* outputStream,
                                 std::string* storeName,
                                 std::string* key,
                                 std::string* value,
                                 VectorClock* version,
                                 bool shouldReroute);
    virtual void readPutResponse(std::istream* inputStream);
    virtual void writeDeleteRequest(std::ostream* outputStream,
                                    std::string* storeName,
                                    std::string* key,
                                    VectorClock* version,
                                    bool shouldReroute);
    virtual bool readDeleteResponse(std::istream* inputStream);
};

} /* namespace Voldemort */

#endif /* VOLDEMORTNATIVEREQUESTFORMAT_H */
