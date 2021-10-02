#ifndef __SPACE_DEPENDENT_DATA__
#define __SPACE_DEPENDENT_DATA__

template <typename T>
struct SpaceDependentData {
    T world_space;
    T camera_space;
};

#endif // __SPACE_DEPENDENT_DATA__
