
/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef POSITIONDATA_HPP
#define POSITIONDATA_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>

using namespace std::string_literals; // NOLINT
class LIB_API PositionData {
    private:
        static constexpr const char* TheShortName = "PositionData";
        static constexpr const char* TheLongName = "PositionData";

    public:
        inline static int32_t ID() {
            return 2001;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        PositionData() = default;
        PositionData(const PositionData&) = default;
        PositionData& operator=(const PositionData&) = default;
        PositionData(PositionData&&) = default;
        PositionData& operator=(PositionData&&) = default;
        ~PositionData() = default;

    public:
        inline PositionData& x(const float &v) noexcept {
            m_x = v;
            return *this;
        }
        inline float x() const noexcept {
            return m_x;
        }
        inline PositionData& y(const float &v) noexcept {
            m_y = v;
            return *this;
        }
        inline float y() const noexcept {
            return m_y;
        }
        inline PositionData& z(const float &v) noexcept {
            m_z = v;
            return *this;
        }
        inline float z() const noexcept {
            return m_z;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("x"s), m_x, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("y"s), m_y, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("z"s), m_z, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("x"s), m_x, visitor);
            doVisit(2, std::move("float"s), std::move("y"s), m_y, visitor);
            doVisit(3, std::move("float"s), std::move("z"s), m_z, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("x"s), m_x, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("y"s), m_y, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("z"s), m_z, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_x{ 0.0f }; // field identifier = 1.
        float m_y{ 0.0f }; // field identifier = 2.
        float m_z{ 0.0f }; // field identifier = 3.
};


template<>
struct isVisitable<PositionData> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<PositionData> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef ORIENTATIONDATA_HPP
#define ORIENTATIONDATA_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>

using namespace std::string_literals; // NOLINT
class LIB_API OrientationData {
    private:
        static constexpr const char* TheShortName = "OrientationData";
        static constexpr const char* TheLongName = "OrientationData";

    public:
        inline static int32_t ID() {
            return 2002;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        OrientationData() = default;
        OrientationData(const OrientationData&) = default;
        OrientationData& operator=(const OrientationData&) = default;
        OrientationData(OrientationData&&) = default;
        OrientationData& operator=(OrientationData&&) = default;
        ~OrientationData() = default;

    public:
        inline OrientationData& roll(const float &v) noexcept {
            m_roll = v;
            return *this;
        }
        inline float roll() const noexcept {
            return m_roll;
        }
        inline OrientationData& pitch(const float &v) noexcept {
            m_pitch = v;
            return *this;
        }
        inline float pitch() const noexcept {
            return m_pitch;
        }
        inline OrientationData& yaw(const float &v) noexcept {
            m_yaw = v;
            return *this;
        }
        inline float yaw() const noexcept {
            return m_yaw;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("roll"s), m_roll, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("pitch"s), m_pitch, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("yaw"s), m_yaw, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("roll"s), m_roll, visitor);
            doVisit(2, std::move("float"s), std::move("pitch"s), m_pitch, visitor);
            doVisit(3, std::move("float"s), std::move("yaw"s), m_yaw, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("roll"s), m_roll, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("pitch"s), m_pitch, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("yaw"s), m_yaw, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_roll{ 0.0f }; // field identifier = 1.
        float m_pitch{ 0.0f }; // field identifier = 2.
        float m_yaw{ 0.0f }; // field identifier = 3.
};


template<>
struct isVisitable<OrientationData> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<OrientationData> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef ANGULARVELOCITYDATA_HPP
#define ANGULARVELOCITYDATA_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>

using namespace std::string_literals; // NOLINT
class LIB_API AngularVelocityData {
    private:
        static constexpr const char* TheShortName = "AngularVelocityData";
        static constexpr const char* TheLongName = "AngularVelocityData";

    public:
        inline static int32_t ID() {
            return 2003;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        AngularVelocityData() = default;
        AngularVelocityData(const AngularVelocityData&) = default;
        AngularVelocityData& operator=(const AngularVelocityData&) = default;
        AngularVelocityData(AngularVelocityData&&) = default;
        AngularVelocityData& operator=(AngularVelocityData&&) = default;
        ~AngularVelocityData() = default;

    public:
        inline AngularVelocityData& angularVelocityX(const float &v) noexcept {
            m_angularVelocityX = v;
            return *this;
        }
        inline float angularVelocityX() const noexcept {
            return m_angularVelocityX;
        }
        inline AngularVelocityData& angularVelocityY(const float &v) noexcept {
            m_angularVelocityY = v;
            return *this;
        }
        inline float angularVelocityY() const noexcept {
            return m_angularVelocityY;
        }
        inline AngularVelocityData& angularVelocityZ(const float &v) noexcept {
            m_angularVelocityZ = v;
            return *this;
        }
        inline float angularVelocityZ() const noexcept {
            return m_angularVelocityZ;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("angularVelocityX"s), m_angularVelocityX, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("angularVelocityY"s), m_angularVelocityY, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("angularVelocityZ"s), m_angularVelocityZ, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("angularVelocityX"s), m_angularVelocityX, visitor);
            doVisit(2, std::move("float"s), std::move("angularVelocityY"s), m_angularVelocityY, visitor);
            doVisit(3, std::move("float"s), std::move("angularVelocityZ"s), m_angularVelocityZ, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("angularVelocityX"s), m_angularVelocityX, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("angularVelocityY"s), m_angularVelocityY, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("angularVelocityZ"s), m_angularVelocityZ, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_angularVelocityX{ 0.0f }; // field identifier = 1.
        float m_angularVelocityY{ 0.0f }; // field identifier = 2.
        float m_angularVelocityZ{ 0.0f }; // field identifier = 3.
};


template<>
struct isVisitable<AngularVelocityData> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<AngularVelocityData> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef ACCELEROMETERDATA_HPP
#define ACCELEROMETERDATA_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>

using namespace std::string_literals; // NOLINT
class LIB_API AccelerometerData {
    private:
        static constexpr const char* TheShortName = "AccelerometerData";
        static constexpr const char* TheLongName = "AccelerometerData";

    public:
        inline static int32_t ID() {
            return 2004;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        AccelerometerData() = default;
        AccelerometerData(const AccelerometerData&) = default;
        AccelerometerData& operator=(const AccelerometerData&) = default;
        AccelerometerData(AccelerometerData&&) = default;
        AccelerometerData& operator=(AccelerometerData&&) = default;
        ~AccelerometerData() = default;

    public:
        inline AccelerometerData& accelerationX(const float &v) noexcept {
            m_accelerationX = v;
            return *this;
        }
        inline float accelerationX() const noexcept {
            return m_accelerationX;
        }
        inline AccelerometerData& accelerationY(const float &v) noexcept {
            m_accelerationY = v;
            return *this;
        }
        inline float accelerationY() const noexcept {
            return m_accelerationY;
        }
        inline AccelerometerData& accelerationZ(const float &v) noexcept {
            m_accelerationZ = v;
            return *this;
        }
        inline float accelerationZ() const noexcept {
            return m_accelerationZ;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("accelerationX"s), m_accelerationX, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("accelerationY"s), m_accelerationY, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("accelerationZ"s), m_accelerationZ, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("accelerationX"s), m_accelerationX, visitor);
            doVisit(2, std::move("float"s), std::move("accelerationY"s), m_accelerationY, visitor);
            doVisit(3, std::move("float"s), std::move("accelerationZ"s), m_accelerationZ, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("accelerationX"s), m_accelerationX, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("accelerationY"s), m_accelerationY, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("accelerationZ"s), m_accelerationZ, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_accelerationX{ 0.0f }; // field identifier = 1.
        float m_accelerationY{ 0.0f }; // field identifier = 2.
        float m_accelerationZ{ 0.0f }; // field identifier = 3.
};


template<>
struct isVisitable<AccelerometerData> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<AccelerometerData> {
    static const bool value = true;
};
#endif

