//
// Created by Leo on 30.04.25.
//

#ifndef DEBUGUTILS_H
#define DEBUGUTILS_H
#include <vector>

namespace utils
{
    class DebugUtils
    {
        public:
        DebugUtils();
        ~DebugUtils();

        bool checkValidationLayerSupport();
        std::vector<const char*> getRequiredExtensions();
    };
}
#endif //DEBUGUTILS_H
