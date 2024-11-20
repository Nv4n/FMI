import { SaveAlt as SaveIcon }  from '@mui/icons-material';
import { Box, CssBaseline, Drawer, Fab } from '@mui/material';
import { Vector } from 'ol/source';
import { useEffect, useState } from 'react';

import FeaturesList from '@scripts/FeaturesList';
import MapWidget from '@scripts/MapWidget';
import createKmlDocument from '@scripts/kml.js';
import { download, serializeDocument } from '@scripts/utils.js';

const DRAWER_WIDTH = 40;
const drawerStyle = (theme) => ({
    '& .MuiDrawer-paper': {
        width: theme.spacing(DRAWER_WIDTH),
    },
});
const contentStyle = (theme) => ({
    width: `calc(100% - ${theme.spacing(DRAWER_WIDTH)})`,
    marginLeft: theme.spacing(DRAWER_WIDTH),
    height: '100%'
});

export default function App() {
    const [layerSource, setLayerSource] = useState(null);
    const [features, setFeatures] = useState([]);
    const handleFeatureDeleted = (feature) => layerSource?.removeFeature(feature);
    const handleSave = () => {
        const kmlDoc = createKmlDocument(features);

        download('map.kml', serializeDocument(kmlDoc));
    };

    useEffect(() => {
        const vectorSource = new Vector();
        const newFeatureHandler = ({ feature }) => {
            feature.setId(crypto.randomUUID());

            const featureName = (prompt('Име:') ?? '').trim();
            feature.set('name', featureName);
        }
        const changeHandler = () => setFeatures(vectorSource.getFeatures());
        vectorSource.addEventListener('addfeature', newFeatureHandler);
        vectorSource.addEventListener('change', changeHandler);

        setLayerSource(vectorSource);

        return () => {
            vectorSource.removeEventListener('addfeature', newFeatureHandler);
            vectorSource.removeEventListener('change', changeHandler);
        };
    }, []);

    return (
        <>
            <CssBaseline />

            <Drawer variant="permanent" anchor="left" sx={drawerStyle}>
                <FeaturesList features={features} onDelete={handleFeatureDeleted} />
            </Drawer>
            <Box sx={contentStyle}>
                <Fab onClick={handleSave} color="primary" variant="extended" sx={(theme) => ({
                    position: 'absolute',
                    bottom: theme.spacing(5),
                    right: theme.spacing(5),
                })}>
                    <SaveIcon sx={{ marginRight: 1 }} />
                    Запиши
                </Fab>

                <MapWidget layerSource={layerSource} />
            </Box>
        </>
    );
}
