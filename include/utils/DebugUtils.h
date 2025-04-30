//
// Created by Leo on 30.04.25.
//

#ifndef DEBUGUTILS_H
#define DEBUGUTILS_H
#include <vector>

namespace utils
{
    const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
    };

    class DebugUtils
    {
    public:
        static constexpr bool enableValidationLayers =
#ifdef NDEBUG
false;
#else
            true;
#endif
        DebugUtils();
        ~DebugUtils();

        static bool checkValidationLayerSupport();
        static std::vector<const char*> getRequiredExtensions();
    };
}
#endif //DEBUGUTILS_H
