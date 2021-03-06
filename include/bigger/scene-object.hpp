#ifndef BIGGER_SCENE_OBJECT_HPP
#define BIGGER_SCENE_OBJECT_HPP

#include <glm/glm.hpp>
#include <memory>

namespace bigger
{
    class Material;

    class SceneObject
    {
    public:
        SceneObject(std::shared_ptr<Material> material = nullptr) : m_material(material) {}

        virtual void update() {}
        virtual void draw(const glm::mat4& parent_transform_matrix = glm::mat4(1.0f)) {}

        glm::mat4 m_rotate_matrix    = glm::mat4(1.0f);
        glm::mat4 m_scale_matrix     = glm::mat4(1.0f);
        glm::mat4 m_translate_matrix = glm::mat4(1.0f);

        glm::mat4 getTransform() const { return m_translate_matrix * m_rotate_matrix * m_scale_matrix; }

        bool m_is_active  = true;
        bool m_is_visible = true;

        std::shared_ptr<Material> m_material;
    };
} // namespace bigger

#endif // BIGGER_SCENE_OBJECT_HPP
