import { Container, CssBaseline, Grid, Typography } from '@mui/material';
import { useState } from 'react';

import mapUrl from '@maps/faculties.kml';
import Map from '@scripts/Map';
import FeatureDetails from '@scripts/FeatureDetails';
import FeatureSelector from '@scripts/FeatureSelector';

export default function App() {
    const [features, setFeatures] = useState([]);
    const [selectedFeature, setSelectedFeature] = useState(null);

    return (
        <>
            <CssBaseline />

            <Container>
                <Grid container spacing={2}>
                    <Grid item xs={12}>
                        <Typography variant='h2'>Карта на факултетите</Typography>
                    </Grid>
                    <Grid item xs={4}>
                        <FeatureSelector
                            features={features}
                            onFeatureSelected={setSelectedFeature}
                        />

                        { selectedFeature ? <FeatureDetails feature={selectedFeature} /> : <></> }
                    </Grid>
                    <Grid item xs={8}>
                        <Map url={mapUrl} feature={selectedFeature} onFeaturesLoaded={setFeatures} />
                    </Grid>
                </Grid>
            </Container>
        </>
    );
}
