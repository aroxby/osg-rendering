#include <osgViewer/Viewer>
#include <osg/Geometry>

int main(int argc, char **argv)
{
    osg::ArgumentParser arguments(&argc, argv);

    osgViewer::Viewer viewer(arguments);
    viewer.setUpViewInWindow( 100, 100, 1024, 768 );

    osg::ref_ptr<osg::Geometry> geometry = new osg::Geometry;

    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
    vertices->push_back(osg::Vec3(-1.0, 0.0, -1.0));
    vertices->push_back(osg::Vec3(-1.0, 0.0, 1.0));
    vertices->push_back(osg::Vec3(1.0, 0.0, 1.0));
    vertices->push_back(osg::Vec3(1.0, 0.0, -1.0));
    geometry->setVertexArray(vertices);

    osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
    colors->push_back(osg::Vec4(1.0, 0.0, 0.0, 1.0));
    colors->push_back(osg::Vec4(0.0, 1.0, 0.0, 1.0));
    colors->push_back(osg::Vec4(0.0, 0.0, 1.0, 1.0));
    colors->push_back(osg::Vec4(1.0, 1.0, 1.0, 1.0));

    geometry->setColorArray(colors);
    geometry->setColorBinding(osg::Geometry::BIND_PER_VERTEX);

    osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array;
    normals->push_back(osg::Vec3(0.0f, -1.0f, 0.0f));

    geometry->setNormalArray(normals);
    geometry->setNormalBinding(osg::Geometry::BIND_OVERALL);

    geometry->addPrimitiveSet(new osg::DrawArrays(GL_QUADS, 0, 4));

    osg::ref_ptr<osg::Geode> geode = new osg::Geode;
    geode->addDrawable(geometry.get());
    viewer.setSceneData(geode);

    return viewer.run();
}