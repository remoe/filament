/*
 * Copyright (C) 2021 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef TNT_FILAMENT_FG2_PASSNODE_H
#define TNT_FILAMENT_FG2_PASSNODE_H

#include "fg2/FrameGraph.h"
#include "fg2/details/DependencyGraph.h"
#include "fg2/details/Utilities.h"

namespace filament::fg2 {

class PassNode : private DependencyGraph::Node {
public:
    PassNode(FrameGraph& fg, const char* name, PassExecutor* base) noexcept;
    PassNode(PassNode&& rhs) noexcept;
    ~PassNode() override;

    PassNode(PassNode const&) = delete;
    PassNode& operator=(PassNode const&) = delete;
    PassNode& operator=(PassNode&&) = delete;

    using NodeID = DependencyGraph::NodeID;

    // constants
    const char* const name = nullptr;                   // our name
    UniquePtr<PassExecutor, LinearAllocatorArena> base; // type eraser for calling execute()

private:
    // virtuals from DependencyGraph::Node
    char const* getName() const override { return name; }
    void onCulled(DependencyGraph* graph) override;
};

} // namespace filament::fg2

#endif //TNT_FILAMENT_FG2_PASSNODE_H
